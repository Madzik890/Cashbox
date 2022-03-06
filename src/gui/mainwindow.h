#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <string>
#include "../../src/domain/shopping/core/ports/incoming/icashbox.hpp"

namespace Ui {
class MainWindow;
}

using namespace Domain::Shopping::Core::Ports::Incoming;

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    static void errorCallback(const std::string &error);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_productListBtn_clicked();
    void on_scanProductBtn_clicked();
    void on_scanProductWScaleBtn_clicked();
    void on_printReceiptBtn_clicked();
    void on_exitBtn_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ICashBox> _cashbox;
};

#endif // MAINWINDOW_H
