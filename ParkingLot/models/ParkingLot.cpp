#pragma once
#include<string>
#include<vector>
#include"./ParkingFloor.cpp"
#include<bits/stdc++.h>

class ParkingLot{
private:
std::string parkingId;
std::vector<ParkingFloor*> floors;
public:

    ParkingLot(std::string& id, int floorsNum, int noOfSlots)
    {
        parkingId = id;
        floors.resize(floorsNum);
        for(int i=0;i<floorsNum;i++)
        {
            floors[i] = new ParkingFloor(std::to_string(i+1),i+1,noOfSlots);
        }
    }

    std::vector<ParkingFloor*>& getFloors()
    {
        return floors;
    }
};