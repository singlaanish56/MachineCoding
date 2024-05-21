// #include<map>
// #include<string>
// #include"../models/Ticket.cpp"
// #include<bits/stdc++.h>

// class TicketManager{
//     private:
//         TicketManager();
//         std::map<std::string, Ticket*> tickets;
//         int sz=0;
//     public:

//         static TicketManager& getInstance()
//         {
//             static TicketManager tm;
//             return tm;
//         }

//         std::string generateTicket(TicketDependencies td)
//         {
//             sz++;
//             Ticket* t = new Ticket(std::to_string(sz), td);
//             tickets[std::to_string(sz)]=t;
//             return std::to_string(sz);
//         } 

// };