#ifndef PRODUCTLIST_TESTCASE_HPP
#define PRODUCTLIST_TESTCASE_HPP

#include <boost/test/included/unit_test.hpp>
#include "../../src/domain/database/core/exceptions/noproductinlistexception.hpp"
#include "../../src/domain/database/core/models/foodmodel.hpp"
#include "../../src/domain/database/core/ports/outgoing/iproductlist.hpp"
#include "../../src/domain/database/infrastructure/fileproductlist.hpp"

#define EXAMPLE_BUFFER "abcd=owoc:1.23;dbcd=jablko:43.2;eszkere=pepsi:69.96;"
#define EXAMPLE_INVALID_BUFFER "asaaaaa;aaaaaaaaaaaa;aaaaaaaaaaaaaa;aaaaa;[;l]n[fgd;g][fdg;./v][sdclr=fdd;sa[]aaaaaa;"

using namespace Domain::Database::Core::Exceptions;
using namespace Domain::Database::Core::Models;
using namespace Domain::Database::Core::Ports::Outgoing;
using namespace Domain::Database::Infrastructure;

BOOST_AUTO_TEST_CASE( ProductListAnalizeBuffer )
{
    const std::string exampleBuffer = EXAMPLE_BUFFER;
    const int bufferSize = exampleBuffer.size();

    FileProductList productList(bufferSize, exampleBuffer);
    const std::map<std::string, FoodModel> list = productList.getList();

    BOOST_CHECK(list.size() == 3);
}

BOOST_AUTO_TEST_CASE( ProductListFindProduct )
{
    const std::string exampleBuffer = EXAMPLE_BUFFER;
    const int bufferSize = exampleBuffer.size();

    FileProductList productList(bufferSize, exampleBuffer);

    bool result = false;
    try
    {
        productList.findProduct("abcd");
    }
    catch(std::exception &ex)
    {
        result = true;
    }

    BOOST_CHECK(!result);
}

BOOST_AUTO_TEST_CASE( ProductListFindInvalidProduct )
{
    const std::string exampleBuffer = EXAMPLE_BUFFER;
    const int bufferSize = exampleBuffer.size();

    FileProductList productList(bufferSize, exampleBuffer);

    bool result = false;
    try
    {
        productList.findProduct("abcdssdgfsdggsdf");
    }
    catch(std::exception &ex)
    {
        result = true;
    }

    BOOST_CHECK(result);
}

BOOST_AUTO_TEST_CASE( ProductListAnalizeInvalidBuffer )
{
    const std::string exampleBuffer = EXAMPLE_INVALID_BUFFER;
    const int bufferSize = exampleBuffer.size();

    FileProductList productList(bufferSize, exampleBuffer);
    const std::map<std::string, FoodModel> list = productList.getList();

    BOOST_TEST(true);
}

#endif // PRODUCTLIST_TESTCASE_HPP
