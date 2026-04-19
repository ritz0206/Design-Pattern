#include "ParkingSpotManagerFactory.h"

ParkingSpotManagerFactory::ParkingSpotManagerFactory(std::string vehicleType)
{
    this->vehicleType = vehicleType;
}

std::unique_ptr<ParkingSpotManager> ParkingSpotManagerFactory::getParkingSpotManager()
{
    if (vehicleType == "TwoWheeler") {
        return std::make_unique<TwoWheelerParkingSpotManager>();
    }

    if (vehicleType == "FourWheeler") {
        return std::make_unique<FourWheelerParkingSpotManager>();
    }

    return nullptr;
}

