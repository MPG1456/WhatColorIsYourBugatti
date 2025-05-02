#pragma once

#include <iostream>
#include "list.h"

using namespace std;

class Vehicle
{
    int id;
    int maxSpeed;
    string company;
    int model;
    string color;
    int yearOfProduction;
    bool availble;

public:
    static int counter;
    Vehicle(int maxSpeed, string company, int model, string color, int YOP);
    int getMaxSpeed(void) const;
    string getCompanyName(void) const;
    int getModel(void) const;
    string getColor(void) const;
    int getYOP(void) const;
    virtual void drive(void) const = 0;
    void showFeatures(void) const;
    int getId(void) const;
};

class Sellable
{
    int price;

public:
    Sellable(int price);
    int getPrice(void) const;
};

class Rentable
{
    int pricePerDay;
    bool isRented;

public:
    Rentable(int price);
    int getPrice(int day);
    bool getRentalStatus(void) const;
    void setRentalStatus(bool status);
};

class Car : public Vehicle, public Sellable
{
public:
    Car(int maxSpeed, string company, int model, string color, int price, int YOP);
    void drive(void) const override;
};

class Motor : public Vehicle, public Sellable, public Rentable
{
public:
    Motor(int maxSpeed, string company, int model, string color, int ppd, int price, int YOP);
    void drive(void) const override;
};

class Bike : public Vehicle, public Rentable
{
public:
    Bike(int maxSpeed, string company, int model, string color, int ppd, int YOP);
    void drive(void) const override;
};

void sell(void);
void rent(void);
void addVehicle(void);
void addCar(Vehicle *);
void addMotor(Vehicle *);
void addBike(Vehicle *);