#include "operation.h"
#include "list.h"

void operation(void)
{
    int action;
    while(true)
    {
        cout << "0. Exit" << endl;
        cout << "1. See All Vehicles" << endl;
        cout << "2. Sell Vehicle" << endl;
        cout << "3. Rent Vehicle" << endl;
        cout << "4. Add New Vehicle" << endl;
        cout << "Enter Desired Action: ";
        cin >> action;
        switch(action)
        {
        case 0:
            return;
        case 1:
            showAll();
            break;
        case 2:
            sell();
            break;
        case 3:
            rent();
            break;
        case 4:
            addVehicle();
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
    }
}