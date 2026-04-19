#include "ParkingSpotManager.h"

TwoWheelerParkingSpotManager::TwoWheelerParkingSpotManager()
{
    this->strategy = std::make_unique<NearToEntrance>();
}

void TwoWheelerParkingSpotManager::addParkingSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle)
{
    parkingSpots.push_back(std::make_unique<TwoWheelerSpot>(spotID, isEmpty, std::move(parkedVehicle)));
}

void TwoWheelerParkingSpotManager::removeParkingSpot(int spotID)
{
    parkingSpots.erase(std::remove_if(parkingSpots.begin(), parkingSpots.end(),
        [spotID](const std::unique_ptr<ParkingSpot>& spot) { return spot->spotID == spotID; }), parkingSpots.end());
}

ParkingSpot* TwoWheelerParkingSpotManager::findEmptySpot()
{
    return this->strategy->findParkingSpot(parkingSpots);
}

FourWheelerParkingSpotManager::FourWheelerParkingSpotManager()
{
    this->strategy = std::make_unique<defaultParkingSpot>();
}

void FourWheelerParkingSpotManager::addParkingSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle)
{
    parkingSpots.push_back(std::make_unique<FourWheelerSpot>(spotID, isEmpty, std::move(parkedVehicle)));
}

void FourWheelerParkingSpotManager::removeParkingSpot(int spotID)
{
    parkingSpots.erase(std::remove_if(parkingSpots.begin(), parkingSpots.end(),
        [spotID](const std::unique_ptr<ParkingSpot>& spot) { return spot->spotID == spotID; }), parkingSpots.end());
}

ParkingSpot* FourWheelerParkingSpotManager::findEmptySpot()
{
    return this->strategy->findParkingSpot(parkingSpots);
}