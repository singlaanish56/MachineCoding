#pragma once
#include<string>

struct TicketDependencies{
    std::string parkingLotID;
    int floorNumber;
    int slotNumber;
};

class Ticket{
private:
    std::string id;
    TicketDependencies ticketDependencies;

public:
    Ticket(std::string tid, TicketDependencies td)
    {
        id=tid;
        ticketDependencies= td;
    }
    //getters

    //setters

};