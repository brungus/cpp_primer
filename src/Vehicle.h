#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle
{
    public:
        Vehicle() = default;
        Vehicle(std::string t, 
                unsigned w, 
                unsigned tSpd, 
                double p, 
                unsigned s, 
                std::string c, 
                bool ac) :
                            type(t), 
                            wheels(w), 
                            topSpeed(tSpd), 
                            currentSpeed(0), 
                            price(p), 
                            seats(s), 
                            color(c), 
                            airConditioner(ac) {}

        void horn();

    private:
        std::string type; // car, bike, truck, plane, etc..
        unsigned wheels;
        unsigned topSpeed;
        double currentSpeed;
        double price;
        unsigned seats;
        std::string color;
        bool airConditioner;
};

#endif
