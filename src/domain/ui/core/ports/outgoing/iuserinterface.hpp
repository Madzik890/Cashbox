#ifndef IUSERINTERFACE_HPP
#define IUSERINTERFACE_HPP

namespace Domain
{
    namespace ui
    {
        namespace Core
        {
            namespace Ports
            {
                namespace Outgoing
                {
                    class IUserInterface
                    {
                    public:
                        IUserInterface(int argc, char **argv);
                        virtual ~IUserInterface() = default;

                        virtual int exec() noexcept = 0;

                    protected:
                        int _argc;
                        char **_argv;
                    };
                }
            }
        }
    }
}

#endif // IUSERINTERFACE_HPP
