#ifndef RECEIPTMODEL_TESTCASE_HPP
#define RECEIPTMODEL_TESTCASE_HPP

#include <array>
#include <map>
#include <boost/test/included/unit_test.hpp>
#include "../src/domain/database/core/models/foodmodel.hpp"
#include "../src/domain/shopping/core/models/receiptmodel.hpp"

using namespace Domain::Database::Core::Models;
using namespace Domain::Shopping::Core::Models;

static ReceiptModel model = ReceiptModel();
static const std::array<FoodModel, 4> foodsModel = { FoodModel("a", 1.0), FoodModel("b", 2.0), FoodModel("c", 3.0), FoodModel("d", 4.0) };

BOOST_AUTO_TEST_CASE( ReceiptModelMap )
{
    const int foodsModelSize = foodsModel.size();
    for(int i = 0; i < foodsModelSize; i++)
    {
        model.addFood(foodsModel[i], i + 1);
    }

   const std::map<FoodModel, int> foodsMap = model.getFoods();

   BOOST_CHECK(foodsMap.size() == foodsModel.size());
}

BOOST_AUTO_TEST_CASE( ReceiptModelTotalPrice )
{
    double foodsTotalPrice = 0;

    const int foodsModelSize = foodsModel.size();
    for(int i = 0; i < foodsModelSize; i++)
    {
        foodsTotalPrice += foodsModel[i].getPrice() * static_cast<double>(i + 1);
    }
    BOOST_CHECK(foodsTotalPrice == model.getTotalPrice());
}

BOOST_AUTO_TEST_CASE( ReceiptModelToString )
{
    const std::string rawToString = "a,1.000000,1;b,2.000000,2;c,3.000000,3;d,4.000000,4;";
    const std::string toString = model.toString();
    BOOST_CHECK(rawToString == toString);
}

#endif // RECEIPTMODEL_TESTCASE_HPP
