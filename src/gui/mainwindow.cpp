#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../domain/shopping/infrastructure/cashbox.hpp"

#include "productlistdialog.h"
#include "receiptdialog.h"
#include "scanproductdialog.h"
#include "scanproductwscaladialog.h"

#include <cassert>
#include <QMessageBox>

using namespace Domain::Shopping::Infrastructre;

void MainWindow::errorCallback(const std::string &error)
{
    QMessageBox msgBox;
    msgBox.setText(error.c_str());
    msgBox.exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _cashbox = std::shared_ptr<ICashBox>(new CashBox());
    _cashbox->setErrorCallback(&MainWindow::errorCallback);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_productListBtn_clicked()
{
    ProductListDialog dialog(_cashbox);
    dialog.exec();
}

void MainWindow::on_scanProductBtn_clicked()
{
    ScanProductDialog dialog(_cashbox);
    dialog.exec();
}

void MainWindow::on_scanProductWScaleBtn_clicked()
{
    ScanProductWScalaDialog  dialog(_cashbox);
    dialog.exec();
}

void MainWindow::on_printReceiptBtn_clicked()
{
    ReceiptDialog dialog(_cashbox);
    dialog.exec();
}

void MainWindow::on_exitBtn_clicked()
{
    close();
}

