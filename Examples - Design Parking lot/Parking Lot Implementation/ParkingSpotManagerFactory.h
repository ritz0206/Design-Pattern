#pragma once

#include <bits/stdc++.h>

#include "ParkingSpotManager.h"

class ParkingSpotManagerFactory
{
    private:
        std::string vehicleType;

    public:
        ParkingSpotManagerFactory(std::string vehicleType);
        std::unique_ptr<ParkingSpotManager> getParkingSpotManager();
};