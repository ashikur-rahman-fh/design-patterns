#pragma once

#include <iostream>
#include <string>

namespace factory {

class Door {
public:
    Door();
    Door(const std::string &attr);
    virtual void open() const = 0;
    virtual void close() const = 0;
    virtual void display_attribute() const = 0;

protected:
    std::string attribute;
};

class Engine {
public:
    virtual void run() = 0;
};

class GasCarDoor : public Door {
public:
    GasCarDoor();
    GasCarDoor(const std::string &attr);
    void open() const;
    void close() const;
    void display_attribute() const;
};

class ElectricCarDoor : public Door {
public:
    ElectricCarDoor();
    ElectricCarDoor(const std::string &attr);
    void open() const;
    void close() const;
    void display_attribute() const;
};

} // factory ends
