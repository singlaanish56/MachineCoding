#include<string>
#include<Vehicle.cpp>



class Slot{
private:
std::string slotid;
int slotNumber;
std::string floorNumber;
VehicleType slotType;
Vehicle* vehicle;
bool isOccupied;

public:
    Slot(std::string& id, int slotNumber, int& floorNumber, VehicleType vt)
    {
        slotid = id;
        slotNumber=slotNumber;
        floorNumber=floorNumber;
        slotType=vt;
        vehicle = NULL;
        isOccupied = false;
    }
//getters

//setters

};