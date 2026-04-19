#pragma once

#include <bits/stdc++.h>

#include "VehicleClass.h"

class ParkingSpot
{
    public:
        int spotID;
        bool isEmpty;
        std::unique_ptr<Vehicle> parkedVehicle;

        ParkingSpot(int spotID);
        ParkingSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle);

        void parkVehicle(std::unique_ptr<Vehicle> vehicle);
        void removeVehicle();

        virtual int price() = 0;
        virtual ~ParkingSpot();
};

class TwoWheelerSpot : public ParkingSpot
{
    public:
        TwoWheelerSpot(int spotID);
        TwoWheelerSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle);
        int price() override;
};

class FourWheelerSpot : public ParkingSpot
{
    public:
        FourWheelerSpot(int spotID);
        FourWheelerSpot(int spotID, bool isEmpty, std::unique_ptr<Vehicle> parkedVehicle);
        int price() override;
};