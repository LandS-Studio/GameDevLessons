#include "Espresso.h"
#include "CoffeeMachine.h"

void Espresso::showInfo() const {
    std::cout << "Espresso" << std::endl;
}

bool Espresso::checkResources(CoffeeMachine& machine) const {
    bool hasResources = true;
    if (machine.getWaterReservoirVolume() < waterNeeded) {
        std::cout << "Not enough water!" << std::endl;
        hasResources = false;
    }
    if (machine.getGrainsContainerVolume() < grainsNeeded) {
        std::cout << "Not enough coffee grains!" << std::endl;
        hasResources = false;
    }
    return hasResources;
}

void Espresso::prepare(CoffeeMachine& machine) {
    machine.useWater(waterNeeded);
    machine.useGrains(grainsNeeded);
    std::cout << std::endl << "Grrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << std::endl << "Preparing... Espresso... ";
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
    std::cout << "Espresso is ready!" << std::endl << std::endl;
}