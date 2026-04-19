#include "ExitGateClass.h"

void ExitGate::processExit(Ticket* ticket)
{
    if (ticket != nullptr && ticket->parkingSpot != nullptr) {
        time_t exitTime = time(0);
        double duration = difftime(exitTime, ticket->entryTime) / 60;
        int price = ticket->parkingSpot->price();

        std::cout << "Vehicle with license plate " << ticket->vehicleLicensePlate
                  << " is exiting. Total price: $" << price << std::endl;

        ticket->parkingSpot->removeVehicle();
    } else {
        std::cout << "Invalid ticket." << std::endl;
    }
}