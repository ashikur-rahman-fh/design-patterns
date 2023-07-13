#include <iostream>
#include <factory.hpp>
#include <behavioral.hpp>

int main() {
    factory::CoffeeMakerFactory coffee_maker;
    auto my_coffee = coffee_maker.get_coffee();
    std::cout << my_coffee -> get_type() << "\n";
    return 0;
}
