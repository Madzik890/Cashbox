#include "fileproductlist.hpp"
#include "../core/exceptions/noproductinlistexception.hpp"

#include <fstream>
#include <iterator>

using namespace Domain::Database::Infrastructure;
using namespace Domain::Database::Core::Exceptions;
using namespace Domain::Database::Core::Models;

FileProductList::FileProductList(const std::string &filePath)
    :Core::Ports::Outgoing::IProductList(),
     _filePath(filePath)
{
    const std::string buffer = getBufferFromFile(filePath);
    const int bufferSize = static_cast<int>(buffer.size());
    analizeBuffer(bufferSize, buffer);
}

FileProductList::FileProductList(const int &size, const std::string &buffer)
{
    analizeBuffer(size, buffer);
}

FileProductList::~FileProductList()
{

}

void FileProductList::addProduct(const std::string code, const Core::Models::FoodModel &model) noexcept
{
    _productList[code] = model;
}

const Domain::Database::Core::Models::FoodModel FileProductList::findProduct(const std::string &code)
{
    if(_productList.find(code) != _productList.end())
        return _productList[code];
    else
        throw NoProductInListException();
}

const std::map<std::string, Domain::Database::Core::Models::FoodModel> FileProductList::getList() const
{
    return _productList;
}

const std::string FileProductList::getBufferFromFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

void FileProductList::analizeBuffer(const int &size, const std::string &buffer)
{    
    (void)size;
    const int bufferSize = buffer.size();

    std::string code;
    std::string name;
    double price;

    int index = 0;
    for(int i = 0; i < bufferSize; i++)
    {
        if(buffer[i] == '=')
        {
            code = buffer.substr(index, i - index);
            index = i + 1;
        }
        else
        if(buffer[i] == ':')
        {
            name = buffer.substr(index, i - index);
            index = i+1;
        }
        else
        if(buffer[i] == ';')
        {
            const std::string value = buffer.substr(index, i - index);
            price = std::atof(value.c_str());

            _productList[code] = FoodModel(name, price);
            index = i + 1;
        }
    }
}
