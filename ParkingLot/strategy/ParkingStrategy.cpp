
#include"../models/ParkingLot.cpp"
#include"../models/Vehicle.cpp"
#include"../models/Ticket.cpp"
class ParkingStrategy{
public:

    virtual Slot* park(ParkingLot* pl,Vehicle* vh) = 0;
};