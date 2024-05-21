#pragma once
#include<map>
#include<string>
#include"../strategy/ParkingStrategy.cpp"
#include"../models/ParkingLot.cpp"
#include"../models/Vehicle.cpp"
#include"../models/Ticket.cpp"
#include<iostream>
class ParkingManager{
private:
    ParkingManager()
    {

    }
    ParkingManager(const ParkingManager&) = delete;
    ParkingManager& operator=(const ParkingManager&) = delete;
    std::map<std::string, ParkingLot*> lots;


public:
    static ParkingManager& getInstance()
    {
        static ParkingManager pm;
        return pm;
    }

    void createParkingLot(std::string id, int numFloors, int noOfSlots)
    {
        //can have own id but going by the problem statement;
        lots[id] = new ParkingLot(id,numFloors,noOfSlots);
    }

    //! TODO - could be be command and parking strategy should be defined once for the parking manager
    Slot* parkVehicle(std::string id, Vehicle* vh, ParkingStrategy* ps)
    {
        if(lots.find(id)==lots.end())
        {
            std::cout<<"No parking lot found"<<std::endl;
            return NULL;
        }
        return ps->park(lots[id], vh);
    }
};