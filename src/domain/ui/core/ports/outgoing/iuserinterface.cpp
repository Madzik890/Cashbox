#include "iuserinterface.hpp"

using namespace Domain::ui::Core::Ports::Outgoing;

IUserInterface::IUserInterface(int argc, char **argv)
    :_argc(argc),
     _argv(argv)
{
}
