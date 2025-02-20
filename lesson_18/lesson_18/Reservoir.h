#pragma once
#include <iostream>

class CoffeeMachine;

class Reservoir {
public:
    virtual ~Reservoir() = default;
    void showMenu(CoffeeMachine& machine);
    void receiveInput(CoffeeMachine& machine);
    void update(CoffeeMachine& machine);

    virtual void clean() = 0;
    virtual void fill(float volume) = 0;
    virtual void use(float volume) = 0;
    virtual void showStatus() const = 0;
    
    virtual float getVolume() const = 0;
    virtual float getMaxVolume() const = 0;
    virtual std::string getName() const = 0;

};
