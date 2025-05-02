#include "vehicle.h"

Vehicle::Vehicle(int maxS, bool iR, bool iS) : maxSpeed(maxS), isRent(iR), isSell(iS)
{}

int Vehicle::getMaxSpeed(void) const
{
    return maxSpeed;
}

bool Vehicle::getRent(void) const
{
    return isRent;
}

bool Vehicle::getSell(void) const
{
    return isSell;
}

