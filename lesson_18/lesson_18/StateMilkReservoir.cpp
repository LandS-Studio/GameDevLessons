#include "StateMilkReservoir.h"

#include "CoffeeMachine.h"

void StateMilkReservoir::showMenu(CoffeeMachine& machine) {
    machine.getMilkReservoir().showMenu(machine);
}

void StateMilkReservoir::receiveInput(CoffeeMachine& machine) {
    machine.getMilkReservoir().receiveInput(machine);
}

void StateMilkReservoir::update(CoffeeMachine& machine) {
    showMenu(machine);
    receiveInput(machine);
}