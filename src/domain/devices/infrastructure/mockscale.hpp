#ifndef MOCKSCALE_HPP
#define MOCKSCALE_HPP

#include "../core/ports/incoming/iscale.hpp"

namespace Domain
{
    namespace Devices
    {
        namespace Infrastructre
        {
            class MockScale final : public Core::Ports::Incoming::IScale
            {
            public:
                MockScale();
                ~MockScale() = default;

                int init() override;
                double getWeigth() override;
                void close() override;
            };
        }
    }
}

#endif // MOCKSCALE_HPP
