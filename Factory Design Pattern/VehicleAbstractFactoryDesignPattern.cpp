#include<bits/stdc++.h>

using namespace std;

class Vehicle
{
    public:
        virtual void features() = 0;
        virtual ~Vehicle() {}
};

class Creata : public Vehicle{
    public:
        void features() override
        {
            cout<<"Features of Creata Car!"<<endl;
        }
};

class Sierra : public Vehicle{
    public:
        void features() override
        {
            cout<<"Features of Sierra Car!"<<endl;
        }
};

class Thar : public Vehicle{
    public:
        void features() override
        {
            cout<<"Features of Thar Car!"<<endl;
        }
};

class BMW : public Vehicle{
    public:
        void features() override
        {
            cout<<"Features of BMW Car!"<<endl;
        }
};

class Mercedes : public Vehicle{
    public:
        void features() override
        {
            cout<<"Features of Mercedes Car!"<<endl;
        }
};

class RollsRoyce : public Vehicle{
    public:
        void features() override
        {
            cout<<"Features of Rolls Royce Car!"<<endl;
        }
};

class AbstractVehicleFactory
{
    public:
        virtual std::unique_ptr<Vehicle> createVehicle(const std::string& vehicleType) = 0;
        virtual ~AbstractVehicleFactory() {}
};

class SUVFactory : public AbstractVehicleFactory
{
    public:
        std::unique_ptr<Vehicle> createVehicle(const std::string& vehicleType) override
        {
            if (vehicleType == "Creata")
                return std::make_unique<Creata>();
            else if (vehicleType == "Sierra")
                return std::make_unique<Sierra>();
            return nullptr;
        }
};

class OffRoadFactory : public AbstractVehicleFactory
{
    public:
        std::unique_ptr<Vehicle> createVehicle(const std::string& vehicleType) override
        {
            if (vehicleType == "Thar")
                return std::make_unique<Thar>();
            return nullptr;
        }
};

class LuxuryVehicleFactory : public AbstractVehicleFactory
{
    public:
        std::unique_ptr<Vehicle> createVehicle(const std::string& vehicleType) override
        {
            if (vehicleType == "BMW")
                return std::make_unique<BMW>();
            else if (vehicleType == "Mercedes")
                return std::make_unique<Mercedes>();
            else if (vehicleType == "RollsRoyce")
                return std::make_unique<RollsRoyce>();
            return nullptr;
        }

};

class VehicleFactoryProducer
{
    public:
        static std::unique_ptr<AbstractVehicleFactory> getFactory(const std::string& factoryType) 
        {
            if (factoryType == "SUV")
                return std::make_unique<SUVFactory>();
            else if (factoryType == "OffRoad")
                return std::make_unique<OffRoadFactory>();
            else if (factoryType == "Luxury")
                return std::make_unique<LuxuryVehicleFactory>();
            return nullptr;
        }
};

int main()
{
    auto suvFactory = VehicleFactoryProducer::getFactory("SUV");
    auto creata = suvFactory->createVehicle("Creata");
    creata->features();

    auto offRoadFactory = VehicleFactoryProducer::getFactory("OffRoad");
    auto thar = offRoadFactory->createVehicle("Thar");
    thar->features();

    auto luxuryFactory = VehicleFactoryProducer::getFactory("Luxury");
    auto rollsRoyce = luxuryFactory->createVehicle("RollsRoyce");
    rollsRoyce->features();

    return 0;
}
