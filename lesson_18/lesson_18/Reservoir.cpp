#include "Reservoir.h"
#include "CoffeeMachine.h"
#include "StateIdle.h"

void Reservoir::showMenu(CoffeeMachine& machine){
    std::cout << std::endl;
    std::cout << "--- Current " << getName() << " level: " << getVolume() << "l out of " << getMaxVolume() << "l max ---" << std::endl;
    std::cout << "1. Clean reservoir" << std::endl;
    std::cout << "2. Fill up with " << getName() << std::endl;
    std::cout << "3. Back to main" << std::endl;
}

void Reservoir::receiveInput(CoffeeMachine& machine){
    int choice;
    std::cout << "Choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 3){
        std::cout << "Invalid choice!" << std::endl;
        machine.setState(std::make_unique<StateIdle>());
    } else if (choice == 3) {
        machine.setState(std::make_unique<StateIdle>());
    } else if (choice == 1) {
        clean();
    } else if (choice == 2) {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << getMaxVolume() << "l) ";
        std::cin >> newVolume;
        
        fill(newVolume);
    }
}

void Reservoir::update(CoffeeMachine& machine){
    std::cout << std::endl;
    showMenu(machine);
    receiveInput(machine);
}