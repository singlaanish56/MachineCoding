
#include"./manager/ParkingManager.cpp"
#include"./manager/TicketManager.cpp"

int main()
{   
    ParkingManager& pm = ParkingManager::getInstance();
   // TicketManager& tm = TicketManager::getInstance();
    
   pm.createParkingLot(std::string("PR1234"),3,6);
    return 0;

}