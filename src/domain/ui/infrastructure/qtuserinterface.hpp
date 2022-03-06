#ifndef QTUSERINTERFACE_HPP
#define QTUSERINTERFACE_HPP

#include "../core/ports/outgoing/iuserinterface.hpp"

namespace Domain
{
    namespace ui
    {
        namespace Interface
        {
            class QtUserInterface final : public Domain::ui::Core::Ports::Outgoing::IUserInterface
            {
            public:
                QtUserInterface(int argc, char **argv);
                ~QtUserInterface();

                int exec() noexcept override;
            };
        }
    }
}

#endif // QTUSERINTERFACE_HPP
