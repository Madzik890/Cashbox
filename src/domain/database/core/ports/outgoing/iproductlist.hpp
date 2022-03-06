#ifndef IPRODUCTLIST_HPP
#define IPRODUCTLIST_HPP

#include "../../models/foodmodel.hpp"
#include <map>

namespace Domain
{
    namespace Database
    {
        namespace Core
        {
            namespace Ports
            {
                namespace Outgoing
                {
                    class IProductList
                    {
                    public:
                        IProductList() = default;
                        virtual ~IProductList() = default;

                        virtual void addProduct(const std::string code, const Models::FoodModel &model) noexcept = 0;
                        virtual const Models::FoodModel findProduct(const std::string &code) = 0;
                        virtual const std::map<std::string, Core::Models::FoodModel> getList() const = 0;
                    };
                }
            }
        }
    }
}

#endif // IPRODUCTLIST_HPP
