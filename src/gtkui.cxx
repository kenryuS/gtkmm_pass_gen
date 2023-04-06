#include "glibmm/ustring.h"
#include "passgen.hxx"
#include "utils.hxx"
#include <gtkui.hxx>

PassGenUI::PassGenUI():
// initialize widgets
m_generate_button("Generate"),
m_main_box(Gtk::Orientation::VERTICAL,widgetMargin),
m_char_checks(Gtk::Orientation::VERTICAL,widgetMargin),
m_output_box(Gtk::Orientation::VERTICAL, widgetMargin),
m_upper_check("Include Upper Case Letters"),
m_lower_check("Include Lower Case Letters"),
m_num_check("Include Numbers"),
m_special_chars_check("Include Special Characters"),
m_title("Password Generator")
{
    // set window props
    set_title("AP CSP Create Task - Password Generator");
    set_default_size(winWidth,winHeight);
    // link the button event to the function
    m_generate_button.signal_clicked().connect(sigc::mem_fun(*this, &PassGenUI::on_generate_button_clicked));

    // populate the widgets and other boxes in main box
    set_child(m_main_box);
    m_main_box.set_margin(widgetMargin);
    m_num_input.set_adjustment(m_num_input_adj);
    m_main_box.append(m_title);
    m_main_box.append(m_char_checks);
    m_main_box.append(m_num_input);
    m_main_box.append(m_generate_button);
    m_main_box.append(m_output_box);

    // populate the widgets in letter configuration section
    m_char_checks.append(m_upper_check);
    m_char_checks.append(m_lower_check);
    m_char_checks.append(m_num_check);
    m_char_checks.append(m_special_chars_check);

    // populate the widgets in ouput section and configure widgets
    m_output_scroll.set_child(m_output);
    m_output_scroll.set_expand();
    m_output.set_editable(false);
    m_output.set_monospace(true);
    m_output.set_cursor_visible(false);
    m_output_style->load_from_data("#m_output {font-size: 14pt;}");
    m_output.set_name("m_output");
    m_output.get_style_context()->add_provider(m_output_style, 1);
    m_output.set_wrap_mode(Gtk::WrapMode::CHAR);
    m_output_box.append(m_output_scroll);
    m_output.set_buffer(m_output_buffer);
}

PassGenUI::~PassGenUI() = default;

auto PassGenUI::showErrorDialog(PassGen::exceptions::exception &e, Glib::ustring extraMsg="") -> void {
    Glib::RefPtr<Gtk::AlertDialog> m_Alert = Gtk::AlertDialog::create();
    m_Alert->set_message("Error!");
    m_Alert->set_detail((Glib::ustring)e.what() + "\n" + extraMsg);
    m_Alert->show(*this);
}

auto PassGenUI::on_generate_button_clicked() -> void {
    // appends letters to input according to the flags
    std::string input;
    try {
        if (m_upper_check.get_active()) {input += PassGen::getUpperAlpha();}
        if (m_lower_check.get_active()) {input += PassGen::getLowerAlpha();}
        if (m_num_check.get_active()) {input += PassGen::getNumber();}
        if (m_special_chars_check.get_active()) {input += PassGen::getSpecialChars();}
    }
    catch (PassGen::exceptions::memoryAllocationFailiure &e) {
        showErrorDialog(e, "Please free some memory.");
        return;
    }
    catch (...) {
        PassGen::exceptions::exception error = PassGen::exceptions::unknownError();
        showErrorDialog(error);
        return;
    }

    // convert std::string to pure C string
    char* cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());

    // get the length of password to be generated
    int len = m_num_input.get_value_as_int();

    // generate password
    char* passwd = nullptr;
    try {
        passwd = PassGen::passGen(cInput, len);
    }
    // Show error alert dialog when passwd threw exceptions
    catch (PassGen::exceptions::memoryAllocationFailiure &e) {
        showErrorDialog(e, "Please free some memory.");
        return;
    }
    catch (PassGen::exceptions::noCharList &e) {
        showErrorDialog(e, "Please check the form.");
        return;
    }
    catch (...) {
        PassGen::exceptions::exception error = PassGen::exceptions::unknownError();
        showErrorDialog(error);
        return;
    }


    // Show the passwd by setting text and buffer
    Glib::ustring output = Glib::convert(passwd, "UTF-8", "ISO-8859-1"); // convert to appropriate type and encoding of text
    m_output_buffer->set_text(output);
    m_output.set_buffer(m_output_buffer);
}
