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
{
}

void Car::drive(void) const
{
    int maxS = getMaxSpeed();
    for (int i = 0; i < maxS; ++i)
        cout << i << " ";
    cout << endl;
}

Motor::Motor(int maxSpeed, string company, int model, string color, int ppd, int price, int YOP) : Vehicle(maxSpeed, company, model, color, YOP), Rentable(ppd), Sellable(price)
{
}

void Motor::drive(void) const
{
    int maxS = getMaxSpeed() / 2;
    for (int i = 0; i < maxS; ++i)
        cout << i << " ";
    cout << endl;
}

Bike::Bike(int maxSpeed, string company, int model, string color, int ppd, int YOP) : Vehicle(maxSpeed, company, model, color, YOP), Rentable(ppd)
{
}

void Bike::drive(void) const
{
    int maxS = getMaxSpeed();
    for (int i = 0; i < maxS; ++i)
        cout << "pedaling ";
    cout << endl;
}

Sellable::Sellable(int price) : price(price)
{
}

int Sellable::getPrice(void) const
{
    return price;
}

Rentable::Rentable(int price) : pricePerDay(price)
{
    isRented = false;
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

void sell(void)
{
    int id;
    Vehicle *myV;
    while (true)
    {
        cout << "Enter ID: ";
        cin >> id;
        myV = findVehicle(id);
        if (myV == nullptr)
            cout << "This ID Does Not Exist" << endl;
        else
            break;
    }
    Sellable *s = dynamic_cast<Sellable *>(myV);
    Motor *m = dynamic_cast<Motor *>(myV);

    if(s)
    {
        if(m && m->getRentalStatus())
        {
            cout << "Cannot Sell a Rented Motor" << endl;
            return;
        }
        cout << "Sold Successfuly for " << s->getPrice() << endl;
        deleteVehicle(myV);
    }
    else
        cout << "This Item Cannot Be Sold" << endl;
}

void rent(void)
{
    int id;
    Vehicle *myV;
    while (true)
    {
        cout << "Enter ID: ";
        cin >> id;
        myV = findVehicle(id);
        if (myV == nullptr)
            cout << "This ID Does Not Exist" << endl;
        else
            break;
    }
    Rentable *r = dynamic_cast<Rentable *>(myV);
    if(r)
    {
        if(r->getRentalStatus())
        {
            cout << "This Item Is Already Rented" << endl;
            return;
        }
        r->setRentalStatus(true);
    }
    else
        cout << "This Item Is Not for Renting" << endl;
}

void addVehicle(void)
{
    int action;
    while(true)
    {
        cout << "0. Exit" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Add Motor" << endl;
        cout << "3. Add Bike" << endl;
        cout << "Enter Desired Action: ";
        cin >> action;
        switch(action)
        {
        case 0:
            return;
        case 1:
            addCar(newVehicle());
            break;
        case 2:
            addMotor(newVehicle());
            break;
        case 3:
            addBike(newVehicle());
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
        }
    }
}

void addCar(Vehicle *myV)
{
    int maxSpeed, model, price, YOP;
    string company, color;
    cout << "Enter Max Speed: ";
    cin >> maxSpeed;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Year Of Production: ";
    cin >> YOP;
    cout << "Enter Company Name: ";
    cin >> company;
    cout << "Enter Color: ";
    cin >> color;
    myV = new Car(maxSpeed, company, model, color, price, YOP);
}

void addMotor(Vehicle *myV)
{
    int maxSpeed, model, ppd, price, YOP;
    string company, color;
    cout << "Enter Max Speed: ";
    cin >> maxSpeed;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Price Per Day: ";
    cin >> ppd;
    cout << "Enter Year Of Production: ";
    cin >> YOP;
    cout << "Enter Company Name: ";
    cin >> company;
    cout << "Enter Color: ";
    cin >> color;
    myV = new Motor(maxSpeed, company, model, color, ppd, price, YOP);
}

void addBike(Vehicle *myV)
{
    int maxSpeed, model, ppd, YOP;
    string company, color;
    cout << "Enter Max Speed: ";
    cin >> maxSpeed;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Price Per Day: ";
    cin >> ppd;
    cout << "Enter Year Of Production: ";
    cin >> YOP;
    cout << "Enter Company Name: ";
    cin >> company;
    cout << "Enter Color: ";
    cin >> color;
    myV = new Bike(maxSpeed, company, model, color, ppd, YOP);
}