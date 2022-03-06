#ifndef FOODMODEL_H
#define FOODMODEL_H

#include <string>

namespace Domain
{
    namespace Database
    {
        namespace Core
        {
            namespace Models
            {
                class FoodModel final
                {
                public:
                    FoodModel() = default;
                    FoodModel(const std::string &name, const double &price);

                    void setPrice(const double &price);
                    void setName(const std::string &name);

                    double getPrice() const;
                    const std::string getName() const;

                    friend bool operator<(const FoodModel& l, const FoodModel& r)
                    {
                        if(l._name != r._name)
                        {
                            if(l._price < r._price)
                                return true;
                            else
                                return false;
                        }
                        else
                            return false;
                    }

                    friend bool operator==(const FoodModel &l, const FoodModel& r)
                    {
                        if(l._price == r._price && l._name == r._name)
                            return true;
                        else
                            return false;
                    }

                private:
                    double _price;
                    std::string _name;
                };
            }
        }
    }
}

#endif // FOODMODEL_H
