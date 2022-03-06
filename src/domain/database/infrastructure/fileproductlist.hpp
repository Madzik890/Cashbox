#ifndef FILEPRODUCTLIST_HPP
#define FILEPRODUCTLIST_HPP

#include "../core/models/foodmodel.hpp"
#include "../core/ports/outgoing/iproductlist.hpp"
#include <map>

namespace Domain
{
    namespace Database
    {
        namespace Infrastructure
        {
            class FileProductList : public Core::Ports::Outgoing::IProductList
            {
            public:
                explicit FileProductList(const std::string &filePath = "productlist.txt");
                explicit FileProductList(const int &size, const std::string &buffer);
                ~FileProductList();

                void addProduct(const std::string code, const Core::Models::FoodModel &model) noexcept override;
                const Core::Models::FoodModel findProduct(const std::string &code) override;
                const std::map<std::string, Core::Models::FoodModel> getList() const override;

            protected:
                const std::string _filePath;
                std::map<std::string, Core::Models::FoodModel> _productList;

            private:
                const std::string getBufferFromFile(const std::string &filePath);
                void analizeBuffer(const int &size, const std::string &buffer);
            };
        }
    }
}

#endif // FILEPRODUCTLIST_HPP
