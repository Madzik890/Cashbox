#include "mockscale.hpp"

using namespace Domain::Devices::Infrastructre;

MockScale::MockScale()
    : Core::Ports::Incoming::IScale()
{

}

int MockScale::init()
{
    return 0;
}

double MockScale::getWeigth()
{
    return 1;
}

void MockScale::close()
{

}
