#include <cassert>

#include "uifactory.hpp"

using namespace Domain::ui::Core::Ports::Outgoing;

int main(int argc, char **argv)
{
    IUserInterface *ui = CreateUi(argc, argv);
    assert(ui);
    return ui->exec();
}
