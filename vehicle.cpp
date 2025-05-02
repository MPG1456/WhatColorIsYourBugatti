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

int Vehicle::getId(void) const
{
    return id;
}

void Vehicle::showFeatures(void) const
{
    cout << "========================" << endl;
    cout << "ID: " << id << endl;
    cout << "Max Speed: " << maxSpeed << endl;
    cout << "Company: " << company << endl;
    cout << "Model: " << model << endl;
    cout << "Color: " << color << endl;
    cout << "Year Of Production: " << yearOfProduction << endl;
    cout << "========================" << endl;
}

Car::Car(int maxSpeed, string company, int model, string color, int YOP) : Vehicle(maxSpeed, false, true, company, model, color, YOP)
{}

void Car::drive(void) const
{
    int maxS = getMaxSpeed();
    for(int i = 0; i < maxS; ++i)
        cout << i << " ";
    cout << endl;
}

Motor::Motor(int maxSpeed, string company, int model, string color, int YOP) : Vehicle(maxSpeed, true, true, company, model, color, YOP)
{}

void Motor::drive(void) const
{
    int maxS = getMaxSpeed() / 2;
    for(int i = 0; i < maxS; ++i)
        cout << i << " ";
    cout << endl;
}