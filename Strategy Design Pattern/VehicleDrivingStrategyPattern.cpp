#include <bits/stdc++.h>

using namespace std;

// Strategy Pattern
class DriveStrategy 
{
    public:
        virtual void drivingstr() = 0;
        virtual ~DriveStrategy() = default;
};

class NormalDrive : public DriveStrategy
{
    public:
        void drivingstr() override
        {
            cout << "Normal Drive Strategy." << endl;
        }
};

class SpecialDrive : public DriveStrategy
{
    public:
        void drivingstr() override
        {
            cout << "Special Drive Strategy." << endl;
        }
};

class Vehicle
{
    private:
        DriveStrategy* driveStr;

    public:
        Vehicle(DriveStrategy* ds) : driveStr(ds) {}

        void drive()
        {
            driveStr->drivingstr();
        }
};

class PassengerCar : public Vehicle{
    public:
        PassengerCar() : Vehicle(new NormalDrive()) {}
};

class SportsCar : public Vehicle{
    public:
        SportsCar() : Vehicle(new SpecialDrive()) {}
};

class OffRoadCar : public Vehicle{
    public:
        OffRoadCar() : Vehicle(new SpecialDrive()) {}
};

int main()
{
    //create context
    Vehicle *passengerCar = new PassengerCar();
    Vehicle *offRoadCar = new OffRoadCar();
    Vehicle *sportsCar = new SportsCar();

    passengerCar->drive();    // Normal driving
    offRoadCar->drive();      // Special driving
    sportsCar->drive();       // Special driving

    return 0;
}