#pragma once

#include <bits/stdc++.h>

#include "ParkingSpotManager.h"
#include "TicketClass.h"
#include "VehicleClass.h"

class EntranceGate
{
    public:
        ParkingSpotManager* psmObj = nullptr;
        std::unique_ptr<Vehicle> vehicle;
        std::unique_ptr<Ticket> ticket;

    void createTicket(std::unique_ptr<Vehicle> vehicle, ParkingSpotManager* manager);
};