#ifndef ISCALE_HPP
#define ISCALE_HPP

namespace Domain
{
    namespace Devices
    {
        namespace Core
        {
            namespace Ports
            {
                namespace Incoming
                {
                    class IScale
                    {
                    public:
                        IScale() = default;
                        virtual ~IScale() = default;

                        virtual int init() = 0;
                        virtual double getWeigth() = 0;
                        virtual void close() = 0;
                    };
                }
            }
        }
    }
}

#endif // ISCALE_HPP
