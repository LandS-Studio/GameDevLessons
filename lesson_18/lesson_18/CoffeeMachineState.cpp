#include "CoffeeMachineState.h"
#include "CoffeeMachine.h"

void CoffeeMachineState::changeState(CoffeeMachine& machine, std::unique_ptr<CoffeeMachineState> newState) {
    machine.setState(std::move(newState));
}
