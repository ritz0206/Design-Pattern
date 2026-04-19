#pragma once

#include <bits/stdc++.h>

#include "ParkingSpotClass.h"

class Ticket
{
    public:
        int ticketID;
        std::string vehicleLicensePlate;
        time_t entryTime;
        ParkingSpot* parkingSpot;

        Ticket(int id, const std::string& licensePlate, ParkingSpot* spot);
        void printTicketDetails();
};