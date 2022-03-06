#include "cashbox.hpp"
#include "../../network/infrastructre/udpreceiptsender.hpp"
#include "../../database/infrastructure/fileproductlist.hpp"
#include "../../devices/infrastructure/mockscale.hpp"

#include <cassert>

using namespace Domain::Shopping::Infrastructre;
using namespace Domain::Shopping::Core::Models;
using namespace Domain::Network::Core::Ports::Outgoing;
using namespace Domain::Network::Infrastructure;
using namespace Domain::Database::Core::Ports::Outgoing;
using namespace Domain::Database::Infrastructure;
using namespace Domain::Devices::Core::Ports::Incoming;
using namespace Domain::Devices::Infrastructre;

CashBox::CashBox()
    : Core::Ports::Incoming::ICashBox()
{
    _productList = dynamic_cast<IProductList*>(new FileProductList());
    _receiptSender = dynamic_cast<IReceiptSender*>(new UdpRecepitSender());
    _scale = dynamic_cast<IScale*>(new MockScale());

    assert(_receiptSender);
    assert(_productList);
    assert(_scale);

    _receiptQueue.push(ReceiptModel());
    _scale->init();
}

CashBox::CashBox(const int &size, const std::string &buffer)
    : Core::Ports::Incoming::ICashBox()
{
    _productList = dynamic_cast<IProductList*>(new FileProductList(size, buffer));
    _receiptSender = dynamic_cast<IReceiptSender*>(new UdpRecepitSender());
    _scale = dynamic_cast<IScale*>(new MockScale());

    assert(_receiptSender);
    assert(_productList);
    assert(_scale);

    _receiptQueue.push(ReceiptModel());
    _scale->init();
}

CashBox::~CashBox()
{
    _scale->close();

    delete _productList;
    delete _receiptSender;
    delete _scale;
}

void CashBox::addFoodToReceipt(const std::string &code, const int &amount)
{
    try
    {
        _receiptQueue.back().addFood(_productList->findProduct(code), amount);
    }
    catch(std::exception &ex)
    {
        _errorCallback(ex.what());
    }
}

void CashBox::addFoodToReceipt(const std::string &code)
{
    try
    {
        _receiptQueue.back().addFood(_productList->findProduct(code), _scale->getWeigth());
    }
    catch(std::exception &ex)
    {
        _errorCallback(ex.what());
    }
}

const Domain::Shopping::Core::Models::ReceiptModel CashBox::getLastReceipt()
{
    auto &result = _receiptQueue.back();

    sendReceptToServer(result);

    _receiptQueue.push(ReceiptModel());
    return result;
}

const std::map<std::string, Domain::Database::Core::Models::FoodModel> CashBox::getProductList() const
{
    return _productList->getList();
}

double CashBox::getScalaWeight() const
{
    return _scale->getWeigth();
}

void CashBox::sendReceptToServer(const Core::Models::ReceiptModel &receipt)
{
    try
    {
        _receiptSender->sendReceipt(receipt);
    }
    catch(std::exception &ex)
    {
        _errorCallback(ex.what());
    }
}
