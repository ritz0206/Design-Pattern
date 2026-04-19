#include "ParkingSpotClass.h"

ParkingSpot::ParkingSpot(int spotID)
{
    this->spotID = spotID;
    this->isEmpty = true;
    this->parkedVehicle = nullptr;
}

ParkingSpot::ParkingSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle)
{
    this->spotID = spotID;
    this->isEmpty = isEmpty;
    this->parkedVehicle = std::move(parkedVehicle);
}

void ParkingSpot::parkVehicle(std::unique_ptr<Vehicle> vehicle)
{
    parkedVehicle = std::move(vehicle);
    isEmpty = false;
}

void ParkingSpot::removeVehicle()
{
    parkedVehicle = nullptr;
    isEmpty = true;
}

ParkingSpot::~ParkingSpot() {}

TwoWheelerSpot::TwoWheelerSpot(int spotID) : ParkingSpot(spotID) {}

TwoWheelerSpot::TwoWheelerSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle)
    : ParkingSpot(spotID, isEmpty, std::move(parkedVehicle)) {}

int TwoWheelerSpot::price()
{
    return 20;
}

FourWheelerSpot::FourWheelerSpot(int spotID) : ParkingSpot(spotID) {}

FourWheelerSpot::FourWheelerSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle)
    : ParkingSpot(spotID, isEmpty, std::move(parkedVehicle)) {}

int FourWheelerSpot::price()
{
    return 50;
}