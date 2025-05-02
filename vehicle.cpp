#include "vehicle.h"

int Vehicle::counter = 0;

Vehicle::Vehicle(int maxS, bool iR, bool iS, string company, int model, string color, int YOP) : maxSpeed(maxS), isRent(iR), isSell(iS), company(company), model(model), color(color), yearOfProduction(YOP)
{
    availble = true;
    id = ++counter;
}

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

string Vehicle::getCompanyName(void) const
{
    return company;
}

int Vehicle::getModel(void) const
{
    return model;
}

string Vehicle::getColor(void) const
{
    return color;
}

int Vehicle::getYOP(void) const
{
    return yearOfProduction;
}

bool Vehicle::getAvailable(void) const
{
    return availble;
}

void Vehicle::setAvailable(bool status)
{
    availble = status;
}

