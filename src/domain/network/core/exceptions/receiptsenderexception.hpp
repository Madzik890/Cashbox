#ifndef RECEIPTSENDEREXCEPTION_HPP
#define RECEIPTSENDEREXCEPTION_HPP

#include <exception>
#include <string>

namespace Domain
{
    namespace Network
    {
        namespace Core
        {
            namespace Exceptions
            {
                class ReceiptSenderException final : public std::exception
                {
                public:
                    ReceiptSenderException(const std::string &error = "Cannot send receipt to the server")
                        :std::exception(),
                          _error(error)
                    {

                    }

                    const char *what() const throw()
                    {
                        return _error.c_str();
                    }

                private:
                    std::string _error;
                };
            }
        }
    }
}

#endif // RECEIPTSENDEREXCEPTION_HPP
