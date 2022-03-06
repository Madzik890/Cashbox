#include "productlistdialog.h"
#include "ui_productlistdialog.h"

ProductListDialog::ProductListDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductListDialog),
    _cashbox(cashbox)
{
    ui->setupUi(this);
    printProducts();
}

ProductListDialog::~ProductListDialog()
{
    delete ui;
}

void ProductListDialog::printProducts()
{
    const std::map<std::string, Domain::Database::Core::Models::FoodModel> productList = _cashbox->getProductList();
    for(auto &product : productList)
    {
        const QString textLine = QString(product.first.c_str()) + ":" + product.second.getName().c_str() + "=" + QString::number(product.second.getPrice()) + '\n';
        ui->textEdit->append(textLine);
    }
}
