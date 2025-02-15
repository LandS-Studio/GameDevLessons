#pragma once
#include <chrono>
#include <thread>
#include <iostream>

class CoffeeMachine; 

class DrinkProgram {
public:
    virtual ~DrinkProgram() = default;
    
    virtual void showInfo() const = 0;
    virtual bool checkResources(CoffeeMachine& context) const = 0;
    virtual void prepare(CoffeeMachine& context) = 0;
};