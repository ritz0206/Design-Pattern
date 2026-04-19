#pragma once

#include <bits/stdc++.h>

class Vehicle
{
    public:
        std::string licensePlate;
        enum VehicleType {TwoWheeler, FourWheeler} type;

        Vehicle(std::string licensePlate, VehicleType type);
};