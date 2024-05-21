
#include"ParkingStrategy.cpp"
#include"../models/ParkingFloor.cpp"
#include"../models/Slot.cpp"
#include<iostream>
class DefaultParkingStrategy : public ParkingStrategy{
public:

    Slot* park(ParkingLot* pl, Vehicle* vh)
    {
        bool parked =false;
        for(ParkingFloor* pf : pl->getFloors())
        {
            auto& slots = pf->getEmptySlots(vh->getType());
            if(slots.size()==0)
                break;
            
            Slot* x = slots[0];
            slots.erase(0);
            x->setVehicle(vh);

            pf->occupySlot(x, vh->getType());
            parked=true;
            std::cout<<"Vehicle Parked at Floor "<<pf->getFloorNumber()<<" Slot No "<<pf->getSlotNumber()<<std::endl;
        }

        if(!parked)
            std::cout<<"No Slots available, Vehicle Cannot be parked"<<std::endl;

    }
};