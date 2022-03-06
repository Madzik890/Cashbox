TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console

isEmpty(BOOST_INCLUDE_DIR): BOOST_INCLUDE_DIR=$$(BOOST_INCLUDE_DIR)
!isEmpty(BOOST_INCLUDE_DIR): INCLUDEPATH *= $${BOOST_INCLUDE_DIR}

isEmpty(BOOST_INCLUDE_DIR): {
    message("BOOST_INCLUDE_DIR is not set, assuming Boost can be found automatically in your system")
}

SOURCES += \
    ../src/domain/database/core/models/foodmodel.cpp \
    ../src/domain/database/infrastructure/fileproductlist.cpp \
    ../src/domain/devices/infrastructure/mockscale.cpp \
    ../src/domain/network/infrastructre/udpreceiptsender.cpp \
    ../src/domain/shopping/core/models/receiptmodel.cpp \
    ../src/domain/shopping/core/ports/incoming/icashbox.cpp \
    ../src/domain/shopping/infrastructure/cashbox.cpp \
    main.cpp

HEADERS += \
    ../src/domain/database/core/exceptions/noproductinlistexception.hpp \
    ../src/domain/database/core/models/foodmodel.hpp \
    ../src/domain/database/core/ports/outgoing/iproductlist.hpp \
    ../src/domain/database/infrastructure/fileproductlist.hpp \
    ../src/domain/devices/core/ports/incoming/iscale.hpp \
    ../src/domain/devices/infrastructure/mockscale.hpp \
    ../src/domain/network/core/exceptions/receiptsenderexception.hpp \
    ../src/domain/network/core/ports/outgoing/ireceiptsender.hpp \
    ../src/domain/network/infrastructre/udpreceiptsender.hpp \
    ../src/domain/shopping/core/models/receiptmodel.hpp \
    ../src/domain/shopping/core/ports/incoming/icashbox.hpp \
    ../src/domain/shopping/infrastructure/cashbox.hpp \
    cashbox_testcase.hpp \
    productlist_testcase.hpp \
    receiptmodel_testcase.hpp \
    scale_testcase.hpp
