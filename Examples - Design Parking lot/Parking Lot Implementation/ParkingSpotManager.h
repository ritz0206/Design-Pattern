#pragma once

#include <bits/stdc++.h>

#include "ParkingSpotClass.h"
#include "ParkingSpotStrategyClass.h"

class ParkingSpotManager
{
    protected:
        std::unique_ptr<ParkingSpotStrategy> strategy;

    public:
        virtual void addParkingSpot(int spotID, bool isEmpty = true, std::unique_ptr<Vehicle> parkedVehicle = nullptr) = 0;
        virtual void removeParkingSpot(int spotID) = 0;
        virtual ParkingSpot* findEmptySpot() = 0;
        virtual ~ParkingSpotManager() = default;
};

class TwoWheelerParkingSpotManager : public ParkingSpotManager
{
    private:
        std::vector<std::unique_ptr<ParkingSpot>> parkingSpots;

    public:
        TwoWheelerParkingSpotManager();
        void addParkingSpot(int spotID, bool isEmpty = true, std::unique_ptr<Vehicle> parkedVehicle = nullptr) override;
        void removeParkingSpot(int spotID) override;
        ParkingSpot* findEmptySpot() override;
};

class FourWheelerParkingSpotManager : public ParkingSpotManager
{
    private:
        std::vector<std::unique_ptr<ParkingSpot>> parkingSpots;

    public:
        FourWheelerParkingSpotManager();
        void addParkingSpot(int spotID, bool isEmpty = true, std::unique_ptr<Vehicle> parkedVehicle = nullptr) override;
        void removeParkingSpot(int spotID) override;
        ParkingSpot* findEmptySpot() override;
};