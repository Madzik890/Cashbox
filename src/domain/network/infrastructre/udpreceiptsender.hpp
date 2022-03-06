#ifndef UDPRECEIPTSENDER_HPP
#define UDPRECEIPTSENDER_HPP

#include "../core/ports/outgoing/ireceiptsender.hpp"
#include <string>

namespace Domain
{
    namespace Network
    {
        namespace Infrastructure
        {
            class UdpRecepitSender final : public Core::Ports::Outgoing::IReceiptSender
            {
            public:
                UdpRecepitSender(const std::string &ip = "127.0.0.1", const int &port = 8088);
                ~UdpRecepitSender();

                void sendReceipt(const Shopping::Core::Models::ReceiptModel &receipt) override;

            private:
                const std::string _ip;
                const int _port;
            };
        }
    }
}

#endif // UDPRECEIPTSENDER_HPP
