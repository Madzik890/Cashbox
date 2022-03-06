#include "qtuserinterface.hpp"

#include <QApplication>
#include "../../../gui/mainwindow.h"

using namespace Domain::ui::Interface;

QtUserInterface::QtUserInterface(int argc, char **argv)
   : Domain::ui::Core::Ports::Outgoing::IUserInterface(argc, argv)
{

}

QtUserInterface::~QtUserInterface()
{

}

int QtUserInterface::exec() noexcept
{
    QApplication a(_argc, _argv);
    MainWindow w;
    w.show();
    return a.exec();
}
