#include <cassert>

#include "domain/ui/core/ports/outgoing/iuserinterface.hpp"
#include "domain/ui/infrastructure/terminaluserinterface.hpp"
#include "domain/ui/infrastructure/qtuserinterface.hpp"

using namespace Domain::ui::Core::Ports::Outgoing;
using namespace Domain::ui::Interface;

int main(int argc, char **argv)
{
    //IUserInterface *ui = dynamic_cast<IUserInterface*>(new TerminalUserInterface(argc, argv));

    IUserInterface *ui = dynamic_cast<IUserInterface*>(new QtUserInterface(argc, argv));
    assert(ui);

    return ui->exec();
}
