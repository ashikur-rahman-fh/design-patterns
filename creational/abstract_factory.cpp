#include <iostream>

#include <abstract_factory.hpp>

namespace factory {

Door::Door() = default;
Door::Door(const std::string &attr) : attribute(attr) {}

GasCarDoor::GasCarDoor() = default;
GasCarDoor::GasCarDoor(const std::string &attr) : Door(attr) {}

void GasCarDoor::open() const {
    std::cout << attribute << " " << "is opening." << std::endl;
}

void GasCarDoor::close() const {
    std::cout << attribute << " " << "is closing." << std::endl;
}

void GasCarDoor::display_attribute() const {
    std::cout << "This is a" << " " << attribute << "." << std::endl;
}

ElectricCarDoor::ElectricCarDoor() = default;
ElectricCarDoor::ElectricCarDoor(const std::string &attr) : Door(attr) {}

void ElectricCarDoor::open() const {
    std::cout << attribute << " " << "is opening." << std::endl;
}

void ElectricCarDoor::close() const {
    std::cout << attribute << " " << "is closing." << std::endl;
}

void ElectricCarDoor::display_attribute() const {
    std::cout << "This is a" << " " << attribute << "." << std::endl;
}

}   // factory ends
