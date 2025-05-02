#pragma once

#include <iostream>
#include "vehicle.h"

using namespace std;

struct VEHICLE_LIST
{
    Vehicle *myV;
    VEHICLE_LIST *vNext;
};

extern struct VEHICLE_LIST *vHead;

Vehicle *newVehicle(void);
Vehicle *findVehicle(int id);
void deleteVehicle(Vehicle *);
