#pragma once

#include <bits/stdc++.h>

#include "ParkingSpotClass.h"

class ParkingSpotStrategy
{
    public:
        virtual ParkingSpot* findParkingSpot(std::vector<std::unique_ptr<ParkingSpot>>& ps) = 0;
        virtual ~ParkingSpotStrategy();
};

class NearToEntrance : public ParkingSpotStrategy
{
    public:
        ParkingSpot* findParkingSpot(std::vector<std::unique_ptr<ParkingSpot>>& ps) override;
};

class defaultParkingSpot : public ParkingSpotStrategy
{
    public:
        ParkingSpot* findParkingSpot(std::vector<std::unique_ptr<ParkingSpot>>& ps) override;
};