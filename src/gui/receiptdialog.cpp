#include "receiptdialog.h"
#include "ui_receiptdialog.h"

using namespace Domain::Shopping::Core::Models;
using namespace Domain::Database::Core::Models;

ReceiptDialog::ReceiptDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiptDialog),
    _cashbox(cashbox)
{
    ui->setupUi(this);
    printReceipt();
}

ReceiptDialog::~ReceiptDialog()
{
    delete ui;
}

void ReceiptDialog::printReceipt()
{
    const ReceiptModel receipt = _cashbox->getLastReceipt();
    const std::map<FoodModel, int> foods = receipt.getFoods();

    for(auto &food : foods)
    {
        const double price = food.first.getPrice() * static_cast<double>(food.second);
        const QString line = QString(food.first.getName().c_str()) + "  " + QString::number(food.first.getPrice()) + "*" + QString::number(food.second) + "=" + QString::number(price);
        ui->textEdit->append(line);
    }

    ui->priceLabel->setText(QString::number(receipt.getTotalPrice()));
}
