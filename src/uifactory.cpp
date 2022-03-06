#include "uifactory.hpp"
#include "domain/ui/infrastructure/terminaluserinterface.hpp"
#include "domain/ui/infrastructure/qtuserinterface.hpp"
#include <string>

using namespace Domain::ui::Interface;

IUserInterface *CreateUi(const int &argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        const std::string arg = argv[i];
        if(arg == "gui")
        {
            return new QtUserInterface(argc, argv);
        }
    }
    return new TerminalUserInterface(argc, argv);
}
