#include "ParkingSpotStrategyClass.h"

ParkingSpotStrategy::~ParkingSpotStrategy() {}

ParkingSpot* NearToEntrance::findParkingSpot(std::vector<std::unique_ptr<ParkingSpot>>& ps)
{
    std::sort(ps.begin(), ps.end(), [](const std::unique_ptr<ParkingSpot>& a, const std::unique_ptr<ParkingSpot>& b)
    {
        return a->spotID < b->spotID;
    });

    for (auto& spot : ps) {
        if (spot->isEmpty) {
            return spot.get();
        }
    }

    return nullptr;
}

ParkingSpot* defaultParkingSpot::findParkingSpot(std::vector<std::unique_ptr<ParkingSpot>>& ps)
{
    for (auto& spot : ps) {
        if (spot->isEmpty) {
            return spot.get();
        }
    }

    return nullptr;
}
