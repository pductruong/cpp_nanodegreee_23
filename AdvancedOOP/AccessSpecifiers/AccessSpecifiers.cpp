// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : private Vehicle {
public:
    bool kickstand = true;
};

class Scooter : protected Vehicle {
public:
    bool electric = false;
};

int main() 
{
    Car car;
    car.Print();
    Bicycle bicycle;
    bicycle.Print();
    Scooter scooter;
    scooter.Print();
}