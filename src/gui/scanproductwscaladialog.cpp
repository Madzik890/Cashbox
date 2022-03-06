#include "scanproductwscaladialog.h"
#include "ui_scanproductwscaladialog.h"

ScanProductWScalaDialog::ScanProductWScalaDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanProductWScalaDialog),
    _cashbox(cashbox)
{
    ui->setupUi(this);
    ui->scalaLabel->setText(QString::number(_cashbox->getScalaWeight()));
}

ScanProductWScalaDialog::~ScanProductWScalaDialog()
{
    delete ui;
}

void ScanProductWScalaDialog::on_pushButton_clicked()
{
    const std::string code = ui->lineEdit->text().toStdString();
    _cashbox->addFoodToReceipt(code);
}

