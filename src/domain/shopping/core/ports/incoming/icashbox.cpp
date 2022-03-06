#include "icashbox.hpp"
#include <iostream>

using namespace Domain::Shopping::Core::Ports::Incoming;

void ICashBox::DefaultErrorCallback(const std::string &error)
{
    std::cout << error << std::endl;
}

ICashBox::ICashBox()
    : _errorCallback(&ICashBox::DefaultErrorCallback)
{

}

double ICashBox::getScalaWeight() const
{
    return 1.0;
}

void ICashBox::setErrorCallback(const ErrorCallback errorCallback)
{
    _errorCallback = errorCallback;
}

void ICashBox::sendReceptToServer(const Models::ReceiptModel &receipt)
{
    (void)receipt;
}
