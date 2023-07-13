#include <iostream>
#include <string>
#include <factory.hpp>
#include <memory>

namespace factory {
Coffee::Coffee() = default;
Coffee::Coffee(const std::string &_type) : type(_type) {}
void Coffee::set_type(const std::string &_type) {
    type = _type;
}
std::string Coffee::get_type() const {
    return type;
}

Espresso::Espresso() = default;
Espresso::Espresso(const std::string &_type) : Coffee(_type) {
    std::cout << "Making a cup of Espresso" << std::endl;
    std::cout << "Griding and brewing one scoop of espresso bean" << std::endl;
}

Cappuccino::Cappuccino() = default;
Cappuccino::Cappuccino(const std::string &_type) : Coffee(_type) {
    std::cout << "Making a cup of Cappuccino" << std::endl;
    std::cout << "Griding and brewing one scoop of espresso bean" << std::endl;
    std::cout << "Heating and foming milk" << std::endl;
}

std::unique_ptr<Coffee> CoffeeMakerFactory::get_coffee() {
    int choice;
    std::cout << "Enter 1 for Cappuccino or 2 for Espresso: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        return std::make_unique<Coffee>(Cappuccino("Cappuccino"));
        break;
    case 2:
        return std::make_unique<Coffee>(Espresso("Espresso"));
        break;
    default:
        break;
    }

    return std::make_unique<Coffee>(Coffee("Regular"));
}

} // end factory
