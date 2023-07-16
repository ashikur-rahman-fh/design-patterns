#include <iostream>

#include <abstract_factory.hpp>

namespace factory {

Door::Door() = default;
Door::Door(const std::string &attr) : attribute(attr) {}

Engine::Engine() = default;
Engine::Engine(const std::string &attr) : attribute(attr) {}

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

GasCarEngine::GasCarEngine() = default;
GasCarEngine::GasCarEngine(const std::string &attr) : Engine(attr) {}

void GasCarEngine::run() const {
    std::cout << attribute << " " << "is running." << std::endl;
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

ElectricCarEngine::ElectricCarEngine() = default;
ElectricCarEngine::ElectricCarEngine(const std::string &attr) : Engine(attr) {}

void ElectricCarEngine::run() const {
    std::cout << attribute << " " << "is running." << std::endl;
}

CarFactory::CarFactory() = default;
GasCarFactory::GasCarFactory() = default;
ElectricCarFactory::ElectricCarFactory() = default;

std::unique_ptr<Door> GasCarFactory::make_door() const {
    return std::make_unique<GasCarDoor> ("Gas Car Door");
}

std::unique_ptr<Engine> GasCarFactory::make_engine() const {
    return std::make_unique<GasCarEngine> ("Gas Car Engine");
}

std::unique_ptr<Door> ElectricCarFactory::make_door() const {
    return std::make_unique<ElectricCarDoor>("Electric Car Door");
}

std::unique_ptr<Engine> ElectricCarFactory::make_engine() const {
    return std::make_unique<ElectricCarEngine> ("Electric Car Engine");
}

}   // factory ends
