#ifndef GTKUI
#define GTKUI

#include <gtkmm.h>

class PassGenUI : public Gtk::Window
{
    public:
        PassGenUI();
        ~PassGenUI();
        void on_button_clicked();
    private:
        Gtk::Button m_button;
};

#endif // GTKUI
