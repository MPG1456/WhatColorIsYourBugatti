#include "list.h"

struct VEHICLE_LIST *vHead = nullptr;

Vehicle *newVehicle(void)
{
    struct VEHICLE_LIST *vTemp = vHead;
    if(vHead == nullptr)
        vHead = new struct VEHICLE_LIST;
    else
    {
        while(vTemp->vNext != nullptr)
            vTemp = vTemp->vNext;
        
        vTemp->vNext = new struct VEHICLE_LIST;
        return vTemp->vNext->myV;
    }
}

Vehicle *findVehicle(int id)
{
    struct VEHICLE_LIST *vTemp = vHead;
    while(vTemp)
    {
        if(vTemp->myV->getId() == id)
            return vTemp->myV;
    }
    return nullptr;
}

void deleteVehicle(Vehicle *myV)
{
    struct VEHICLE_LIST *vTemp = vHead, *vTemp2;
    if(vHead->myV == myV)
    {
        vTemp = vTemp->vNext;
        delete vHead->myV;
        delete vHead;
        vHead = vTemp;
        return;
    }

    while(vTemp)
    {
        if(vTemp->vNext->myV == myV)
            break;
    }
    vTemp2 = vTemp->vNext;
    vTemp->vNext = vTemp2->vNext;
    delete vTemp2->myV;
    delete vTemp2;
}

void showAll(void)
{
    struct VEHICLE_LIST *vTemp = vHead;
    if(vHead == nullptr)
    {
        cout << "No Vehicles To Display!" << endl;
        return;
    }

    while(vTemp)
    {
        vTemp->myV->showFeatures();
        vTemp = vTemp->vNext;
    }
}

void deleteAll(void)
{
    struct VEHICLE_LIST *vTemp = vHead;
    if(vHead == nullptr)
        return;

    while(vTemp)
    {
        vTemp = vTemp->vNext;
        delete vHead->myV;
        delete vHead;
        vHead = vTemp;
    }
}