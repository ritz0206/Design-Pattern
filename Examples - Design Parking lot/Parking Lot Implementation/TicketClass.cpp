#include "TicketClass.h"

Ticket::Ticket(int id, const std::string& licensePlate, ParkingSpot* spot)
{
    this->ticketID = id;
    this->vehicleLicensePlate = licensePlate;
    this->parkingSpot = spot;
    this->entryTime = time(0);
}

void Ticket::printTicketDetails()
{
    std::cout << "Ticket ID: " << ticketID << std::endl;
    std::cout << "Vehicle License Plate: " << vehicleLicensePlate << std::endl;
    std::cout << "Entry Time: " << ctime(&entryTime);
    std::cout << "Parking Spot ID: " << parkingSpot->spotID << std::endl;
}