#include "StateGrainsContainer.h"

#include "CoffeeMachine.h"

void StateGrainsContainer::showMenu(CoffeeMachine& machine) {
    machine.getGrainsContainer().showMenu(machine);
}

void StateGrainsContainer::receiveInput(CoffeeMachine& machine) {
    machine.getGrainsContainer().receiveInput(machine);
}

void StateGrainsContainer::update(CoffeeMachine& machine) {
    showMenu(machine);
    receiveInput(machine);
}