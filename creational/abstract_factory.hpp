#pragma once

#include <iostream>
#include <string>
#include <memory>

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
    Engine();
    Engine(const std::string &attr);
    virtual void run() const = 0;
protected:
    std::string attribute;
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

class GasCarEngine : public Engine {
public:
    GasCarEngine();
    GasCarEngine(const std::string &attr);
    void run() const;
};

class ElectricCarEngine : public Engine {
public:
    ElectricCarEngine();
    ElectricCarEngine(const std::string &attr);
    void run() const;
};

class CarFactory {
public:
    CarFactory();
    virtual std::unique_ptr<Door> make_door() const = 0;
    virtual std::unique_ptr<Engine> make_engine() const = 0;
};

class GasCarFactory : public CarFactory {
public:
    GasCarFactory();
    std::unique_ptr<Door> make_door() const;
    std::unique_ptr<Engine> make_engine() const;
};

class ElectricCarFactory : public CarFactory {
public:
    ElectricCarFactory();
    std::unique_ptr<Door> make_door() const;
    std::unique_ptr<Engine> make_engine() const;
};

} // factory ends
