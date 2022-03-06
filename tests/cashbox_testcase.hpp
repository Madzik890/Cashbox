#ifndef CASHBOX_TESTCASE_HPP
#define CASHBOX_TESTCASE_HPP

#include <cassert>
#include <boost/test/included/unit_test.hpp>
#include "../../src/domain/database/core/models/foodmodel.hpp"
#include "../../src/domain/shopping/core/models/receiptmodel.hpp"
#include "../../src/domain/shopping/core/ports/incoming/icashbox.hpp"
#include "../../src/domain/shopping/infrastructure/cashbox.hpp"

using namespace Domain::Database::Core::Models;
using namespace Domain::Shopping::Core::Models;
using namespace Domain::Shopping::Core::Ports::Incoming;
using namespace Domain::Shopping::Infrastructre;


class CashBoxMock : public CashBox
{
public:
    CashBoxMock()
    {
        FoodModel model1("1234", 1.0);
        FoodModel model2("234", 2.0);
        FoodModel model3("4", 3.0);

        _productList->addProduct("1", model1);
        _productList->addProduct("2", model2);
        _productList->addProduct("3", model3);
    }
};

static bool calledError = false;
static ICashBox *cashBox = nullptr;

void errorCallback(const std::string &error)
{
    (void)error;
    calledError = true;
}

BOOST_AUTO_TEST_CASE( CashBoxInit )
{
    cashBox = new CashBoxMock();
    cashBox->setErrorCallback(&errorCallback);
    assert(cashBox);
}

BOOST_AUTO_TEST_CASE( CashBoxCreateReceipt )
{
    cashBox->addFoodToReceipt("1", 1);
    cashBox->addFoodToReceipt("2", 1);

    const ReceiptModel receipt = cashBox->getLastReceipt();
    const int receiptSize = receipt.getFoods().size();
    BOOST_CHECK(receiptSize == 2);
    BOOST_CHECK(receipt.getTotalPrice() == 3);
}

BOOST_AUTO_TEST_CASE( ProductListInvalidProduct )
{
    calledError = false;

    cashBox->addFoodToReceipt("1234123", 12312312);

    BOOST_CHECK(calledError);
}

BOOST_AUTO_TEST_CASE( CashBoxClose )
{
    delete cashBox;
}


#endif // CASHBOX_TESTCASE_HPP
