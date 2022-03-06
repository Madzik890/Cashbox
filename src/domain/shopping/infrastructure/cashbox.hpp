#ifndef CASHBOX_HPP
#define CASHBOX_HPP

#include "../core/models/receiptmodel.hpp"
#include "../core/ports/incoming/icashbox.hpp"
#include "../../network/core/ports/outgoing/ireceiptsender.hpp"
#include "../../database/core/ports/outgoing/iproductlist.hpp"
#include "../../devices/core/ports/incoming/iscale.hpp"
#include <queue>

namespace Domain
{
    namespace Shopping
    {
        namespace Infrastructre
        {
            class CashBox : public Core::Ports::Incoming::ICashBox
            {
            public:
                CashBox();
                CashBox(const int &size, const std::string &buffer);
                ~CashBox();

                void addFoodToReceipt(const std::string &code, const int &amount) override;
                void addFoodToReceipt(const std::string &code) override;
                const Core::Models::ReceiptModel getLastReceipt() override;
                const std::map<std::string, Domain::Database::Core::Models::FoodModel> getProductList() const override;
                double getScalaWeight() const override;

            protected:
                std::queue<Core::Models::ReceiptModel> _receiptQueue;
                Database::Core::Ports::Outgoing::IProductList *_productList;
                Network::Core::Ports::Outgoing::IReceiptSender *_receiptSender;
                Devices::Core::Ports::Incoming::IScale *_scale;

                void sendReceptToServer(const Core::Models::ReceiptModel &receipt) override;
            };
        }
    }
}

#endif // CASHBOX_HPP
