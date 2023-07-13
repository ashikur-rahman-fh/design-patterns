#pragma once

#include <iostream>
#include <string>
#include <memory>

namespace factory {
class Coffee{
public:
    Coffee();
    Coffee(const std::string &_type);
    void set_type(const std::string &_type);
    std::string get_type() const;
private:
    std::string type;
};

class Espresso : public Coffee {
public:
    Espresso();
    Espresso(const std::string &_type);
};

class Cappuccino : public Coffee {
public:
    Cappuccino();
    Cappuccino(const std::string &_type);
};


class CoffeeMakerFactory {
public:
    std::unique_ptr<Coffee> get_coffee();
private:
    Coffee* coffee;
};

} // end factory
