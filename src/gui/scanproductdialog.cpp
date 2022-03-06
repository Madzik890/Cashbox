#include "scanproductdialog.h"
#include "ui_scanproductdialog.h"

ScanProductDialog::ScanProductDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanProductDialog),
    _cashbox(cashbox)
{
    ui->setupUi(this);
}

ScanProductDialog::~ScanProductDialog()
{
    delete ui;
}

void ScanProductDialog::on_pushButton_clicked()
{
    const std::string code = ui->lineEdit->text().toStdString();
    const int amount = ui->spinBox->value();

    _cashbox->addFoodToReceipt(code, amount);
}

