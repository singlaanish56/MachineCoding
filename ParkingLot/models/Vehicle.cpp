#include<string>


enum class VehicleType{
    CAR,
    BIKE,
    TRUCK
};

class Vehicle{
private:
    VehicleType type;
    std::string regNumber;
    std::string color;

public:
    Vehicle(VehicleType type,std::string& regNumber,std::string& color){
        this->type=type;
        this->regNumber=regNumber;
        this->color=color;
    }

    VehicleType getType()
    {
        return type;
    }

    std::string getRegNumber()
    {
        return regNumber;
    }

    std::string getColor()
    {
        return color;
    }
};

// class Car : public Vehicle{
// public:
//     Car(std::string& regNumber,std::string& color)
//     {

//     }
// };