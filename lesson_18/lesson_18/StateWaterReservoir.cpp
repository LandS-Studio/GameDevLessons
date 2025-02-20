#include "StateWaterReservoir.h"

#include "CoffeeMachine.h"

void StateWaterReservoir::showMenu(CoffeeMachine& machine) {
    machine.getWaterReservoir().showMenu(machine);
}

void StateWaterReservoir::receiveInput(CoffeeMachine& machine) {
    machine.getWaterReservoir().receiveInput(machine);
}

void StateWaterReservoir::update(CoffeeMachine& machine) {
    showMenu(machine);
    receiveInput(machine);
}
