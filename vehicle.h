#pragma once

#include <iostream>

using namespace std;

class Vehicle
{
    int id;
    int maxSpeed;
    bool isRent;
    bool isSell;
    string company;
    int model;
    string color;
    int yearOfProduction;
    bool availble;
    
public:
    static int counter;
    Vehicle(int maxSpeed, bool isRent, bool isSell, string company, int model, string color, int YOP);
    int getMaxSpeed(void) const;
    bool getRent(void) const;
    bool getSell(void) const;
    string getCompanyName(void) const;
    int getModel(void) const;
    string getColor(void) const;
    int getYOP(void) const;
    virtual void drive(void) const = 0;
    virtual void showFeatures(void) const = 0;
    bool getAvailable(void) const;
    void setAvailable(bool status);
    int getId(void) const;
};

