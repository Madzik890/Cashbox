#ifndef RECEIPTDIALOG_H
#define RECEIPTDIALOG_H

#include <QDialog>
#include <memory>
#include "../../src/domain/shopping/core/ports/incoming/icashbox.hpp"

namespace Ui {
class ReceiptDialog;
}

using namespace Domain::Shopping::Core::Ports::Incoming;

class ReceiptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiptDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent = nullptr);
    ~ReceiptDialog();

private:
    Ui::ReceiptDialog *ui;
    std::shared_ptr<ICashBox> _cashbox;

    void printReceipt();
};

#endif // RECEIPTDIALOG_H
