#ifndef PRODUCTLISTDIALOG_H
#define PRODUCTLISTDIALOG_H

#include <QDialog>
#include <memory>
#include "../../src/domain/shopping/core/ports/incoming/icashbox.hpp"

namespace Ui {
class ProductListDialog;
}

using namespace Domain::Shopping::Core::Ports::Incoming;

class ProductListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProductListDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent = nullptr);
    ~ProductListDialog();

private:
    Ui::ProductListDialog *ui;
    std::shared_ptr<ICashBox> _cashbox;

    void printProducts();
};

#endif // PRODUCTLISTDIALOG_H
