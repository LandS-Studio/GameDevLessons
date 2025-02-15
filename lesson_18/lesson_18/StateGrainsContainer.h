#pragma once
#include "CoffeeMachineState.h"

class StateGrainsContainer : public CoffeeMachineState {
public:
    void showMenu(CoffeeMachine& machine) override;
    void receiveInput(CoffeeMachine& machine) override;
    void update(CoffeeMachine& machine) override;    
};
