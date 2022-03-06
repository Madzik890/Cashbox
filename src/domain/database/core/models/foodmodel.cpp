#include "foodmodel.hpp"

using namespace Domain::Database::Core::Models;

FoodModel::FoodModel(const std::string &name, const double &price)
    :_price(price), _name(name)
{

}

void FoodModel::setPrice(const double &price)
{
    _price = price;
}

void FoodModel::setName(const std::string &name)
{
    _name = name;
}

double FoodModel::getPrice() const
{
    return _price;
}

const std::string FoodModel::getName() const
{
    return _name;
}
