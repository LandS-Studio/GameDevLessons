#include "GreenTea.h"
#include "CoffeeMachine.h"

void GreenTea::showInfo() const {
    std::cout << "Green Tea" << std::endl;
}

bool GreenTea::checkResources(CoffeeMachine& machine) const {
    if (machine.getWaterReservoirVolume() < waterNeeded) {
        std::cout << "Not enough water!" << std::endl;
        return false;
    }
    return true;
}

void GreenTea::prepare(CoffeeMachine& machine) {
    machine.useWater(waterNeeded);
    std::cout << std::endl << "Grrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << std::endl << "Preparing... Green Tea... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE! ";
    std::cout << "Green Tea is ready!" << std::endl << std::endl;
}