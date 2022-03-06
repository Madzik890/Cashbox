#include "receiptmodel.hpp"
#include <cassert>

using namespace Domain::Shopping::Core::Models;
using namespace Domain::Database::Core::Models;

void ReceiptModel::addFood(const FoodModel &food, const int &amount)
{
    if(_foods.find(food) != _foods.end())
        _foods.insert(std::make_pair(food, amount));
    else
        _foods[food] += amount;
}

const std::map<FoodModel, int> ReceiptModel::getFoods() const
{
    return _foods;
}

double ReceiptModel::getTotalPrice() const
{
    double result = 0;

    for(auto &food : _foods)
    {
        const double foodPrice = food.first.getPrice();
        assert(foodPrice >= 0.0);
        result += food.first.getPrice() * food.second;
    }
    return result;
}

const std::string ReceiptModel::toString() const
{
    std::string result;

    for(auto &food : _foods)
        result += food.first.getName() + ',' + std::to_string(food.first.getPrice()) + ',' + std::to_string(food.second) + ';';

    return result;
}
