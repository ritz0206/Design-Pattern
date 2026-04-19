#include "EntranceGateClass.h"

void EntranceGate::createTicket(std::unique_ptr<Vehicle> vehicle, ParkingSpotManager* manager)
{
    this->vehicle = std::move(vehicle);
    this->psmObj = manager;

    if (psmObj == nullptr) {
        std::cout << "Parking manager is not available." << std::endl;
        ticket = nullptr;
        return;
    }

    ParkingSpot* spot = psmObj->findEmptySpot();
    if (spot != nullptr)
    {
        static int nextTicketID = 1;

        spot->parkVehicle(std::move(this->vehicle));
        ticket = std::make_unique<Ticket>(nextTicketID++, spot->parkedVehicle->licensePlate, spot);
    }
    else
    {
        std::cout << "No parking spot available for the vehicle." << std::endl;
        ticket = nullptr;
    }
}