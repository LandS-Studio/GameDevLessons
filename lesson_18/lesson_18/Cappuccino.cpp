#include "Cappuccino.h"
#include "CoffeeMachine.h"

void Cappuccino::showInfo() const {
    std::cout << "Cappuccino" << std::endl;
}

bool Cappuccino::checkResources(CoffeeMachine& machine) const {
    bool hasResources = true;
    if (machine.getWaterReservoirVolume() < waterNeeded) {
        std::cout << "Not enough water!" << std::endl;
        hasResources = false;
    }
    if (machine.getMilkReservoirVolume() < milkNeeded) {
        std::cout << "Not enough milk!" << std::endl;
        hasResources = false;
    } else if (machine.getMilkReservoir().isMilkSpoiled()) {
        std::cout << "Milk is spoiled!" << std::endl;
        hasResources = false;
    }
    if (machine.getGrainsContainerVolume() < grainsNeeded) {
        std::cout << "Not enough grains!" << std::endl;
        hasResources = false;
    }
    return hasResources;
}

void Cappuccino::prepare(CoffeeMachine& machine) {
    machine.useWater(waterNeeded);
    machine.useMilk(milkNeeded);
    machine.useGrains(grainsNeeded);
    std::cout << std::endl << "Grrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << std::endl << "Preparing... Cappuccino... ";
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
    std::cout << "Cappuccino is ready!" << std::endl << std::endl;
}
