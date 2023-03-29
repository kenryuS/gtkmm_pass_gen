#ifndef GTKUI
#define GTKUI

#include <gtkmm.h>
#include <passgen.hxx>

class PassGenUI : public Gtk::Window
{
    public:
        PassGenUI(); // constructor
        ~PassGenUI(); // destructor
        /**
         * @brief The button event for m_generate_button
         * @return (void) Generate password, set to m_output_buffer, and show to the user
         */
        auto on_generate_button_clicked() -> void; // button event
    private:
        const int winHeight = 400;
        const int winWidth = 600;
        const int padding = 10;
        Gtk::CheckButton m_upper_check, m_lower_check, m_num_check, m_special_chars_check; // checkboxes
        Gtk::Box m_char_checks, m_output_box, m_main_box; // boxes (containers)
        Gtk::Label m_title;
        Gtk::Button m_generate_button;
        Gtk::SpinButton m_num_input;
        Glib::RefPtr<Gtk::Adjustment> m_num_input_adj = Gtk::Adjustment::create(0, 0, 8192); // sets range for m_num_input (0-8192)
        Gtk::ScrolledWindow m_output_scroll;
        Gtk::TextView m_output;
        Glib::RefPtr<Gtk::TextBuffer> m_output_buffer = Gtk::TextBuffer::create(); // text buffer for m_output
};

#endif // GTKUI
