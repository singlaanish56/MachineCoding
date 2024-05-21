#pragma once
#include<string>
#include"Vehicle.cpp"



class Slot{
private:
std::string slotid;
int slotNumber;
int floorNumber;
VehicleType slotType;
Vehicle* vehicle;
bool isOccupied;

public:
    Slot(std::string id, int slotNumber, int floorNumber, VehicleType vt)
    {
        slotid = id;
        slotNumber=slotNumber;
        floorNumber=floorNumber;
        slotType=vt;
        vehicle = NULL;
        isOccupied = false;
    }
//getters
    int getSlotNumber()
    {
        return slotNumber;
    }
//setters
    void setVehicle(Vehicle* vh)
    {
        vehicle=vh;
        isOccupied=true;
    }
};