#ifndef NOPRODUCTINLISTEXCEPTION_HPP
#define NOPRODUCTINLISTEXCEPTION_HPP

#include <exception>

namespace Domain
{
    namespace Database
    {
        namespace Core
        {
            namespace Exceptions
            {
                class NoProductInListException final : public std::exception
                {
                public:
                    NoProductInListException() = default;
                    const char *what() const throw()
                    {
                        return "Brak produktu w bazie";
                    }
                };
            }
        }
    }
}

#endif // NOPRODUCTINLISTEXCEPTION_HPP
