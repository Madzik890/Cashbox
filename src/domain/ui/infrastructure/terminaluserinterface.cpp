#include "terminaluserinterface.hpp"
#include "../../shopping/infrastructure/cashbox.hpp"
#include <cassert>
#include <iostream>

using namespace Domain::ui::Interface;
using namespace Domain::Shopping::Core::Ports::Incoming;
using namespace Domain::Shopping::Infrastructre;
using namespace Domain::Shopping::Core::Models;
using namespace Domain::Database::Core::Models;

void TerminalUserInterface::ErrorCallback(const std::string &error)
{
    std::cout << "Error: " << error << std::endl;
}

TerminalUserInterface::TerminalUserInterface(int argc, char **argv)
    : Core::Ports::Outgoing::IUserInterface(argc, argv)
{
    _cashbox = dynamic_cast<ICashBox*>(new CashBox());
    assert(_cashbox);
}

TerminalUserInterface::~TerminalUserInterface()
{
    delete _cashbox;
}

int TerminalUserInterface::exec() noexcept
{
    while(true)
    {
        clearTerminal();
        printMenu();

        int choise = 0;
        std::cout << "Wybór: ";
        std::cin >> choise;
        choiseFunc(choise);
    }

    return 0;
}

void TerminalUserInterface::printMenu()
{
    std::cout << "Kasa dla skleupu warzyno-owocowego" << std::endl;
    std::cout << "1. Baza produktów" << std::endl;
    std::cout << "2. Zeskanuj produkt" << std::endl;
    std::cout << "3. Zeskanuj produkt(waga)" << std::endl;
    std::cout << "4. Wydrukuj paragon" << std::endl;
    std::cout << "5. Wyjście" << std::endl;
}

void TerminalUserInterface::choiseFunc(const int &choise)
{
    switch(choise)
    {
    case 1:
        printDataBase();
        break;
    case 2:
        addProduct();
        break;
    case 3:
        addProductWScale();
        break;

    case 4:
        printReceipt();
        break;

    case 5:
        exit();
        break;

    default:
        clearTerminal();
        printMenu();
    }
}

void TerminalUserInterface::clearTerminal()
{
    std::cout << "------------------------------------------------------------" << std::endl;
/*#if  defined __linux__ || defined __unix__
    std::system("clear");
#else
    std::system("cls");
#endif*/
}

void TerminalUserInterface::printDataBase()
{
    std::cout << "Baza produktów" << std::endl;

    const std::map<std::string, Domain::Database::Core::Models::FoodModel> productList =_cashbox->getProductList();
    for(auto& product : productList)
    {
        std::cout << product.first << ":" << product.second.getName() << "=" << product.second.getPrice() << std::endl;;
    }
    std::cin.get();
}

void TerminalUserInterface::addProduct()
{
    std::cout << "Dodaj produkt" << std::endl;
    std::string code;
    int amount;

    std::cout << "Podaj kod produktu: ";
    std::cin >> code;
    std::cout << "Podaj ilość: ";
    std::cin >> amount;

    _cashbox->addFoodToReceipt(code, amount);
    std::cin.get();
}

void TerminalUserInterface::addProductWScale()
{
    std::cout << "Dodaj produkt(waga)" << std::endl;
    std::string code;

    std::cout << "Podaj kod produktu: ";
    std::cin >> code;

    _cashbox->addFoodToReceipt(code);
    std::cin.get();
}

void TerminalUserInterface::printReceipt()
{
    std::cout << "Wydruk paragonu" << std::endl;
    const ReceiptModel receipt = _cashbox->getLastReceipt();
    const std::map<FoodModel, int> mapFoodModel = receipt.getFoods();

    std::cout << "Paragon: " << std::endl;
    for(auto &food : mapFoodModel)
    {
        const double price = food.first.getPrice();
        const int amount = food.second;
        std::cout << " - " << food.first.getName() << " * " << amount << " = " << price * static_cast<double>(amount) << std::endl;
    }
    std::cout << "Łączna cena: " << receipt.getTotalPrice() << std::endl;
    std::cin.get();
}

void TerminalUserInterface::exit()
{
    ::exit(0);
}
