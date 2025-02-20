#include "StateIdle.h"
#include "CoffeeMachine.h"
#include "StateDrinkSelection.h"
#include "StateMilkReservoir.h"
#include "StateWaterReservoir.h"
#include "StateGrainsContainer.h"

void StateIdle::showMenu(CoffeeMachine& machine) {
    std::cout << "1. Select drink" << std::endl;
    std::cout << "2. Check water reservoir" << std::endl;
    std::cout << "3. Check milk reservoir" << std::endl;
    std::cout << "4. Check grains container" << std::endl;
    std::cout << "5. Show machine status" << std::endl;
    std::cout << "6. Power off" << std::endl;
    std::cout << std::endl;
}

void StateIdle::receiveInput(CoffeeMachine& machine) {
    int choice;
    std::cout << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    if (choice == 1) {
        changeState(machine, std::make_unique<StateDrinkSelection>());
    } else if (choice == 2) {
        changeState(machine, std::make_unique<StateWaterReservoir>());
    } else if (choice == 3) {
        changeState(machine, std::make_unique<StateMilkReservoir>());
    } else if (choice == 4) {
        changeState(machine, std::make_unique<StateGrainsContainer>());
    } else if (choice == 5) {
        machine.showMachineStatus();
    } else if (choice == 6){
        machine.powerOff();
    }else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

void StateIdle::update(CoffeeMachine& machine) {
    showMenu(machine);
    receiveInput(machine);
}
