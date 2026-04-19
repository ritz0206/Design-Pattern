#include <bits/stdc++.h>

#include "EntranceGateClass.h"
#include "ExitGateClass.h"
#include "ParkingSpotManagerFactory.h"

int main()
{
    //add parking spots to the parking lot
    auto twoWheelerManager = ParkingSpotManagerFactory("TwoWheeler").getParkingSpotManager();
    for (int i = 1; i <= 5; i++) {
        if(i==1 || i==2 || i==4)
        {
            twoWheelerManager->addParkingSpot(i, false, std::make_unique<Vehicle>("KA-02-YY-0000", Vehicle::TwoWheeler));
        }
        else
        {
            twoWheelerManager->addParkingSpot(i);
        }
    }
    //four wheeler parking spots
    auto fourWheelerManager = ParkingSpotManagerFactory("FourWheeler").getParkingSpotManager();
    for (int i = 1; i <= 5; i++) {
        if(i==2 || i==4)
        {
            fourWheelerManager->addParkingSpot(i, false, std::make_unique<Vehicle>("KA-01-XX-0000", Vehicle::FourWheeler));
        }
        else
        {
            fourWheelerManager->addParkingSpot(i);
        }
    }

    //console input for vehicle details
    std::string licensePlate;
    int vehicleTypeInput;
    std::cout << "Enter vehicle type (0 for TwoWheeler, 1 for FourWheeler): ";
    std::cin >> vehicleTypeInput;
    std::cout << "Enter license plate number: ";
    std::cin >> licensePlate;

    std::unique_ptr<Vehicle> vehicle;
    if (vehicleTypeInput == 0) {
        vehicle = std::make_unique<Vehicle>(licensePlate, Vehicle::TwoWheeler);
    } else if (vehicleTypeInput == 1) {
        vehicle = std::make_unique<Vehicle>(licensePlate, Vehicle::FourWheeler);
    } else {
        std::cout << "This vehicle type is not allowed." << std::endl;
        return 1;
    }

    ParkingSpotManager* selectedManager = vehicleTypeInput == 0
        ? twoWheelerManager.get()
        : fourWheelerManager.get();

    EntranceGate entrancegate;
    entrancegate.createTicket(std::move(vehicle), selectedManager);
    if (entrancegate.ticket != nullptr) {
        entrancegate.ticket->printTicketDetails();
    } else {
        std::cout << "No parking spot available for the vehicle." << std::endl;
        return 1;
    }

    ExitGate exitGate;
    exitGate.processExit(entrancegate.ticket.get());
}
