#pragma once
#include <memory>
#include <iostream>

class CoffeeMachine;

class CoffeeMachineState {
public:
    virtual ~CoffeeMachineState() = default;

    virtual void showMenu(CoffeeMachine& machine) = 0;
    virtual void receiveInput(CoffeeMachine& machine) = 0;
    virtual void update(CoffeeMachine& machine) = 0;

protected:
    void changeState (CoffeeMachine& machine, std::unique_ptr<CoffeeMachineState> newState);
};
