#include "VehicleClass.h"

Vehicle::Vehicle(std::string licensePlate, VehicleType type)
{
    this->licensePlate = licensePlate;
    this->type = type;
}