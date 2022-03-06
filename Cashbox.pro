QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/domain/database/core/models/foodmodel.cpp \
        src/domain/database/infrastructure/fileproductlist.cpp \
        src/domain/devices/infrastructure/mockscale.cpp \
        src/domain/network/infrastructre/udpreceiptsender.cpp \
        src/domain/shopping/core/models/receiptmodel.cpp \
        src/domain/shopping/core/ports/incoming/icashbox.cpp \
        src/domain/shopping/infrastructure/cashbox.cpp \
        src/domain/ui/core/ports/outgoing/iuserinterface.cpp \
        src/domain/ui/infrastructure/qtuserinterface.cpp \
        src/domain/ui/infrastructure/terminaluserinterface.cpp \
        src/gui/mainwindow.cpp \
        src/gui/productlistdialog.cpp \
        src/gui/receiptdialog.cpp \
        src/gui/scanproductdialog.cpp \
        src/gui/scanproductwscaladialog.cpp \
        src/main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/domain/database/core/exceptions/noproductinlistexception.hpp \
    src/domain/database/core/models/foodmodel.hpp \
    src/domain/database/core/ports/outgoing/iproductlist.hpp \
    src/domain/database/infrastructure/fileproductlist.hpp \
    src/domain/devices/core/ports/incoming/iscale.hpp \
    src/domain/devices/infrastructure/mockscale.hpp \
    src/domain/network/core/exceptions/receiptsenderexception.hpp \
    src/domain/network/core/ports/outgoing/ireceiptsender.hpp \
    src/domain/network/infrastructre/udpreceiptsender.hpp \
    src/domain/shopping/core/models/receiptmodel.hpp \
    src/domain/shopping/core/ports/incoming/icashbox.hpp \
    src/domain/shopping/infrastructure/cashbox.hpp \
    src/domain/ui/core/ports/outgoing/iuserinterface.hpp \
    src/domain/ui/infrastructure/qtuserinterface.hpp \
    src/domain/ui/infrastructure/terminaluserinterface.hpp \
    src/gui/mainwindow.h \
    src/gui/productlistdialog.h \
    src/gui/receiptdialog.h \
    src/gui/scanproductdialog.h \
    src/gui/scanproductwscaladialog.h

FORMS += \
    src/gui/mainwindow.ui \
    src/gui/productlistdialog.ui \
    src/gui/receiptdialog.ui \
    src/gui/scanproductdialog.ui \
    src/gui/scanproductwscaladialog.ui
