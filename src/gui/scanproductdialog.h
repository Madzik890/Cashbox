#ifndef SCANPRODUCTDIALOG_H
#define SCANPRODUCTDIALOG_H

#include <QDialog>
#include <memory>
#include "../../src/domain/shopping/core/ports/incoming/icashbox.hpp"

namespace Ui {
class ScanProductDialog;
}

using namespace Domain::Shopping::Core::Ports::Incoming;

class ScanProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScanProductDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent = nullptr);
    ~ScanProductDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ScanProductDialog *ui;
    std::shared_ptr<ICashBox> _cashbox;
};

#endif // SCANPRODUCTDIALOG_H
