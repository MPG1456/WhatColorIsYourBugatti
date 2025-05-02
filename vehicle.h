#pragma once

#include <iostream>

using namespace std;

class Vehicle
{
    int maxSpeed;
    bool isRent;
    bool isSell;

public:
    Vehicle(int maxSpeed, bool isRent, bool isSell);
    int getMaxSpeed(void) const;
    bool getRent(void) const;
    bool getSell(void) const;
    virtual void drive(void) const = 0;
    virtual void showFeatures(void) const = 0;
};

