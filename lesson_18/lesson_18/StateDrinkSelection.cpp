#include "StateDrinkSelection.h"
#include "CoffeeMachine.h"
#include "StateIdle.h"

void StateDrinkSelection::showMenu(CoffeeMachine& machine) {
    std::cout << "Select a drink:" << std::endl;
    machine.showListOfDrinks();
    std::cout << machine.getRecipesCount() + 1 << ". Exit" << std::endl;
}

void StateDrinkSelection::receiveInput(CoffeeMachine& machine) {
    int drinkIndex;
    std::cout << "Choice: ";
    std::cin >> drinkIndex;

    if (drinkIndex < 1 || drinkIndex > machine.getRecipesCount()) {
        if (drinkIndex == machine.getRecipesCount() + 1) {
            std::cout << "Returning to main menu..." << std::endl;
            std::cout << std::endl;
            changeState(machine, std::make_unique<StateIdle>());
        } else {
            std::cout << "Invalid choice!" << std::endl;
            std::cout << "Returning to main menu..." << std::endl;
            std::cout << std::endl;
            changeState(machine, std::make_unique<StateIdle>());
        }
    } else {
        machine.prepareDrink(drinkIndex);
        changeState(machine, std::make_unique<StateIdle>());
    }
}

void StateDrinkSelection::update(CoffeeMachine& machine) {
    showMenu(machine);
    receiveInput(machine);
}