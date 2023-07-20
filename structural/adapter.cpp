#include <iostream>

#include <adapter.hpp>

namespace structural {

void DemoApi::run() const {
    std::cout << "Running Demo API run method" << std::endl;
}

void LagacyApi::go() const {
    std::cout << "Lagacy API go method" << std::endl; 
}

LagacyAdapter::LagacyAdapter() {
    lagacy_api = std::make_unique<LagacyApi>();
}

void LagacyAdapter::run() const {
    std::cout << "Lagacy Adapter run method" << std::endl;
    lagacy_api -> go();
}

void LagacyClassAdapter::run() const {
    std::cout << "Lagacy class adapter run method" << std::endl;
    go();
}

}   // structural ends