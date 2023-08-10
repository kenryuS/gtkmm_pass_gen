#ifndef GTKUI_HXX
#define GTKUI_HXX
#include <config.h>

#if USE_GTK == 1
#include <gtkmm.h> // GTK GUI Library (C++ wrapper)
#endif

#if USE_GTK == 1
#include <passgen.hxx>

class PassGenUI : public Gtk::Window
{
    public:
        PassGenUI(); // constructor
        ~PassGenUI() override;// destructor

        /**
        * @brief The button event for m_generate_button
        * @return (void) Generate password, set to m_output_buffer, and show to the user
        */
        auto on_generate_button_clicked() -> void; // button event
        
        /**
        * @brief Show error dialog with exceptions and message
        * @param err PassGen::exceptions::exception exception to be reported
        * @param extraMsg Glib::ustring Extra message to be shown along side the reported exception, set empty by default
        * @return (void) Show the dialog
        */
        auto showErrorDialog(PassGen::exceptions::exception &err, Glib::ustring extraMsg) -> void;

    private:
        const int winHeight = 480;
        const int winWidth = 640;
        const int widgetMargin = 10;
        const int maxLength = 8192;

        // checkboxes
        Gtk::CheckButton m_upper_check, m_lower_check, m_num_check, m_special_chars_check;

        // boxes (containers)
        Gtk::Box m_char_checks, m_output_box, m_main_box;

        // title of the program
        Gtk::Label m_title;

        Gtk::Button m_generate_button;

        // length input
        Gtk::SpinButton m_num_input;

        // sets range for m_num_input (0-maxLength)
        Glib::RefPtr<Gtk::Adjustment> m_num_input_adj = Gtk::Adjustment::create(0, 0, maxLength); 

        // Privides CSS to the GTK widget
        Glib::RefPtr<Gtk::CssProvider> m_output_style = Gtk::CssProvider::create();

        // Text area for output
        Gtk::ScrolledWindow m_output_scroll;
        Gtk::TextView m_output;

        // text buffer for m_output
        Glib::RefPtr<Gtk::TextBuffer> m_output_buffer = Gtk::TextBuffer::create();
};
# else

#endif // USE_GTK

#endif // GTKUI_HXX
