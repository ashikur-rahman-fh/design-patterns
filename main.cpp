#include <iostream>
#include <vector>
#include <memory>

#include <factory.hpp>
#include <behavioral.hpp>
#include <abstract_factory.hpp>
#include <adapter.hpp>


void abstructFactoryRunner() {
    int input;
    std::cout << "Enter 1 for gas car or 2 for electric car: ";
    std::cin >> input;
    
    auto runGasCar = [] () {
        std::unique_ptr<factory::CarFactory> carFactory = std::make_unique<factory::GasCarFactory>();
        auto engine = carFactory -> make_engine();
        auto door = carFactory -> make_door();

        door -> open();
        door -> close();
        engine -> run();
    };

    auto runElectricCar = [] () {
        std::unique_ptr<factory::CarFactory> carFactory = std::make_unique<factory::ElectricCarFactory>();
        auto engine = carFactory -> make_engine();
        auto door = carFactory -> make_door();

        door -> open();
        door -> close();
        engine -> run();
    };

    switch (input)
    {
    case 1:
        runGasCar();
        break;
    case 2:
        runElectricCar();
    default:
        std::cout << "Please select a valid option." << std::endl;
        break;
    }
}


void adapterRunner() {
    std::vector<std::shared_ptr<structural::ApiInterface>> apis = {
        std::make_shared<structural::DemoApi>(),
        std::make_shared<structural::LagacyAdapter>(),
        std::make_shared<structural::LagacyClassAdapter>()
    };

    for (const auto api : apis) {
        api -> run();
    }
}

int main() {
    adapterRunner();
    return 0;
}
