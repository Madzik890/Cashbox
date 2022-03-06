#ifndef IRECEIPTSENDER_HPP
#define IRECEIPTSENDER_HPP

#include "../../../../shopping/core/models/receiptmodel.hpp"

namespace Domain
{
    namespace Network
    {
        namespace Core
        {
            namespace Ports
            {
                namespace Outgoing
                {
                    class IReceiptSender
                    {
                    public:
                        IReceiptSender() = default;
                        virtual ~IReceiptSender() = default;

                        virtual void sendReceipt(const Shopping::Core::Models::ReceiptModel &receipt) = 0;
                    };
                }
            }
        }
    }
}

#endif // IRECEIPTSENDER_HPP
