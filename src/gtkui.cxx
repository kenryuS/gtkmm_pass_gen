#include <gtkui.hxx>
#include <iostream>

PassGenUI::PassGenUI()
: m_button("Hello") {
    m_button.set_margin(10);
    m_button.signal_clicked().connect(sigc::mem_fun(*this, &PassGenUI::on_button_clicked));
    set_child(m_button);
}

PassGenUI::~PassGenUI() {
}

void PassGenUI::on_button_clicked() {
    std::cout << "Hello" << std::endl;
}
