#ifndef ICASHBOX_HPP
#define ICASHBOX_HPP

#include "../../models/receiptmodel.hpp"
#include <functional>

namespace Domain
{
    namespace Shopping
    {
        namespace Core
        {
            namespace Ports
            {
                namespace Incoming
                {
                    typedef std::function<void(const std::string&)> ErrorCallback;

                    class ICashBox
                    {
                    private:
                        static void DefaultErrorCallback(const std::string &error);

                    public:
                        ICashBox();
                        virtual ~ICashBox() = default;

                        virtual void addFoodToReceipt(const std::string &code, const int &amount) = 0;
                        virtual void addFoodToReceipt(const std::string &code) = 0;

                        virtual const Models::ReceiptModel getLastReceipt() = 0;                        
                        virtual const std::map<std::string, Domain::Database::Core::Models::FoodModel> getProductList() const = 0;
                        virtual double getScalaWeight() const;

                        void setErrorCallback(const ErrorCallback errorCallback);

                    protected:
                        ErrorCallback _errorCallback;

                        virtual void sendReceptToServer(const Models::ReceiptModel &receipt);
                    };
                }
            }
        }
    }
}

#endif // ICASHBOX_HPP
