#ifndef GTKUI
#define GTKUI

#include <gtkmm.h>
#include <passgen.hxx>
#include <string>
#include <cstring>

class PassGenUI : public Gtk::Window
{
    public:
        PassGenUI();
        ~PassGenUI();
        void on_generate_button_clicked();
    private:
        Gtk::CheckButton m_upper_check, m_lower_check, m_num_check, m_special_chars_check;
        Gtk::Box m_char_checks, m_output_box, m_main_box;
        Gtk::Label m_title;
        Gtk::Button m_generate_button;
        Gtk::SpinButton m_num_input;
        Glib::RefPtr<Gtk::Adjustment> m_num_input_adj = Gtk::Adjustment::create(0, 0, 256);
        Gtk::ScrolledWindow m_output_scroll;
        Gtk::TextView m_output;
        Glib::RefPtr<Gtk::TextBuffer> m_output_buffer = Gtk::TextBuffer::create();
};

#endif // GTKUI
