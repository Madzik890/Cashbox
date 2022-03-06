#ifndef UIFACTORY_HPP
#define UIFACTORY_HPP

#include "domain/ui/core/ports/outgoing/iuserinterface.hpp"

using namespace Domain::ui::Core::Ports::Outgoing;

IUserInterface * CreateUi(const int &argc, char **argv);

#endif // UIFACTORY_HPP
