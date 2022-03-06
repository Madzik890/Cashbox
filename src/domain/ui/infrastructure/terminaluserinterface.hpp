#ifndef TERMINALUSERINTERFACE_HPP
#define TERMINALUSERINTERFACE_HPP

#include "../core/ports/outgoing/iuserinterface.hpp"
#include "../../shopping/core/ports/incoming/icashbox.hpp"
#include <string>

namespace Domain
{
    namespace ui
    {
        namespace Interface
        {
            class TerminalUserInterface final : public Core::Ports::Outgoing::IUserInterface
            {
            private:
                void ErrorCallback(const std::string &error);

            public:
                TerminalUserInterface(int argc, char **argv);
                ~TerminalUserInterface();

                int exec() noexcept override;

            private:
                Shopping::Core::Ports::Incoming::ICashBox *_cashbox;

                void printMenu();
                void choiseFunc(const int &choise);
                void clearTerminal();
                void getChar();

                void printDataBase();
                void addProduct();
                void addProductWScale();
                void printReceipt();
                void exit();
            };
        }
    }
}

#endif // TERMINALUSERINTERFACE_HPP
