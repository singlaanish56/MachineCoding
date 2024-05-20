#include<map>
#include<string>
#include<../models/ParkingLot.cpp>


class ParkingManager{
private:
    ParkingManager();
    std::map<std::string, ParkingLot*> lots;

public:
    static ParkingManager getInstance()
    {
        static ParkingManager pm;
        return pm;
    }

    void createParkingLot(std::string& id, int numFloors, int noOfSlots)
    {
        //can have own id but going by the problem statement;
        lots[id] = new ParkingLot(id,numFloors,noOfSlots);
    }

};