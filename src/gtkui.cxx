#include <gtkui.hxx>
#include <iostream>

PassGenUI::PassGenUI():
// initialize widgets
m_generate_button("Generate"),
m_main_box(Gtk::Orientation::VERTICAL,10),
m_char_checks(Gtk::Orientation::VERTICAL,10),
m_output_box(Gtk::Orientation::VERTICAL, 10),
m_upper_check("Include Upper Case Letters"),
m_lower_check("Include Lower Case Letters"),
m_num_check("Include Numbers"),
m_special_chars_check("Include Special Characters"),
m_title("Password Generator")
{
    set_title("AP CSP Create Task - Password Generator");
    set_default_size(600,400);
    m_generate_button.signal_clicked().connect(sigc::mem_fun(*this, &PassGenUI::on_generate_button_clicked));
    
    // populate the widgets in main box
    set_child(m_main_box);
    m_main_box.set_margin(10);
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
    m_output.set_wrap_mode(Gtk::WrapMode::CHAR);
    m_output_box.append(m_output_scroll);
    m_output.set_buffer(m_output_buffer);
}

PassGenUI::~PassGenUI() = default;

void PassGenUI::on_generate_button_clicked() {
    std::string input;
    // appends letters to input according to the flags
    if (m_upper_check.get_active()) {input += PassGen::getUpperAlpha();}
    if (m_lower_check.get_active()) {input += PassGen::getLowerAlpha();}
    if (m_num_check.get_active()) {input += PassGen::getNumber();}
    if (m_special_chars_check.get_active()) {input += PassGen::getSpecialChars();}
    // convert std::string to pure C string
    char* cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());
    // get the length of password to be generated
    int len = m_num_input.get_value_as_int();
    // generate password and show password to output section
    Glib::ustring output = Glib::convert(PassGen::passGen(cInput, len), "UTF-8", "ISO-8859-1");
    m_output_buffer->set_text(output);
    m_output.set_buffer(m_output_buffer);
}
