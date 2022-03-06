#ifndef SCALE_TESTCASE_HPP
#define SCALE_TESTCASE_HPP

#include <cassert>
#include <boost/test/included/unit_test.hpp>
#include "../src/domain/devices/core/ports/incoming/iscale.hpp"
#include "../src/domain/devices/infrastructure/mockscale.hpp"

using namespace Domain::Devices::Core::Ports::Incoming;
using namespace Domain::Devices::Infrastructre;

BOOST_AUTO_TEST_CASE( MockScaleTest )
{
    static IScale *deviceScale = new MockScale();
    assert(deviceScale);

    BOOST_CHECK(deviceScale->init() == 0);
    BOOST_CHECK(deviceScale->getWeigth() == 1);
    deviceScale->close();

    delete deviceScale;
}

#endif // SCALE_TESTCASE_HPP
