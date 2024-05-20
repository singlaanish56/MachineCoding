#include<string>
#include<Vehicle.cpp>
#include<Slot.cpp>
#include<vector>
#include<map>

class ParkingFloor{
private:
std::string floorId;
int  floorNumber;
int noOfSlots;
std::map<VehicleType, std::vector<Slot*>> emptySlots;
std::map<VehicleType, std::vector<Slot*>> occupiedSlots;

public:
    ParkingFloor(std::string& id, int floorNum, int noOfSlots)
    {
        floorId = id;
        floorNumber = floorNum;
        noOfSlots = noOfSlots;
        createEmptySlots();
    }

//getters

//setters

    //! TODO : maybe a strategy for the how to define the emtpy slot for each floor
    void createEmptySlots()
    {
        if(noOfSlots <= 3)
        {
            std::cout<<"Very Less Slots to create a floor"<<std::endl;
            return;
        }
        emptySlots[VehicleType::TRUCK].push_back(new Slot(to_string(1),1,VehicleType::TRUCK));
        emptySlots[VehicleType::BIKE].push_back(new Slot(to_string(2),2,VehicleType::BIKE));
        emptySlots[VehicleType::BIKE].push_back(new Slot(to_string(3),3,VehicleType::BIKE));

        for(int i=0;i<noOfSlots-3;i++)
        {
            emptySlots[VehicleType::CAR].push_back(new Slot(to_string(i+4),i+4,VehicleType::CAR));
        }

    }
};