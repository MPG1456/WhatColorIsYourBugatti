#include "vehicle.h"

int Vehicle::counter = 0;

Vehicle::Vehicle(int maxS, string company, int model, string color, int YOP) : maxSpeed(maxS), company(company), model(model), color(color), yearOfProduction(YOP)
{
    availble = true;
    id = ++counter;
}

int Vehicle::getMaxSpeed(void) const
{
    return maxSpeed;
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

Car::Car(int maxSpeed, string company, int model, string color, int price, int YOP) : Vehicle(maxSpeed, company, model, color, YOP), Sellable(price)
{}

void Car::drive(void) const
{
    int maxS = getMaxSpeed();
    for(int i = 0; i < maxS; ++i)
        cout << i << " ";
    cout << endl;
}

Motor::Motor(int maxSpeed, string company, int model, string color, int ppd, int price, int YOP) : Vehicle(maxSpeed, company, model, color, YOP), Rentable(ppd), Sellable(price)
{}

void Motor::drive(void) const
{
    int maxS = getMaxSpeed() / 2;
    for(int i = 0; i < maxS; ++i)
        cout << i << " ";
    cout << endl;
}

Bike::Bike(int maxSpeed, string company, int model, string color, int ppd, int YOP) : Vehicle(maxSpeed, company, model, color, YOP), Rentable(ppd)
{}

void Motor::drive(void) const
{
    int maxS = getMaxSpeed();
    for(int i = 0; i < maxS; ++i)
        cout << "pedaling ";
    cout << endl;
}

Sellable::Sellable(int price) : price(price)
{}

int Sellable::getPrice(void) const
{
    return price;
}

Rentable::Rentable(int price) : pricePerDay(price)
{
    isRented = false;
}

bool Rentable::rent(void)
{
    if(isRented == false)
    {
        isRented = true;
        return true;
    }
    else
        return false;
}

int Rentable::getPrice(int day)
{
    return pricePerDay * day;
}

bool Rentable::getRentalStatus(void) const
{
    return isRented;
}

void Rentable::setRentalStatus(bool status)
{
    isRented = status;
}

