#ifndef SCANPRODUCTWSCALADIALOG_H
#define SCANPRODUCTWSCALADIALOG_H

#include <QDialog>
#include <memory>
#include "../../src/domain/shopping/core/ports/incoming/icashbox.hpp"

namespace Ui {
class ScanProductWScalaDialog;
}

using namespace Domain::Shopping::Core::Ports::Incoming;

class ScanProductWScalaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScanProductWScalaDialog(std::shared_ptr<ICashBox> cashbox, QWidget *parent = nullptr);
    ~ScanProductWScalaDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ScanProductWScalaDialog *ui;
    std::shared_ptr<ICashBox> _cashbox;
};

#endif // SCANPRODUCTWSCALADIALOG_H
