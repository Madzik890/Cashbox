#ifndef RECEIPTMODEL_HPP
#define RECEIPTMODEL_HPP

#include "../../../database/core/models/foodmodel.hpp"
#include <map>

namespace Domain
{
    namespace Shopping
    {
        namespace Core
        {
            namespace Models
            {
                class ReceiptModel final
                {
                public:
                    ReceiptModel() = default;
                    ~ReceiptModel() = default;

                    void addFood(const Database::Core::Models::FoodModel &food, const int &amount = 1);
                    const std::map<Database::Core::Models::FoodModel, int> getFoods() const;
                    double getTotalPrice() const;
                    const std::string toString() const;

                private:
                    std::map<Database::Core::Models::FoodModel, int> _foods;
                };
            }
        }
    }
}

#endif // RECEIPTMODEL_H
