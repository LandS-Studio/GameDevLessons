#pragma once
#include <iostream>

class CoffeeMachine;

class CoffeeGrainsContainer {
public:
    CoffeeGrainsContainer() = default;
    ~CoffeeGrainsContainer() = default;

    void showMenu(CoffeeMachine& machine) const;
    void receiveInput(CoffeeMachine& machine);
    void update(CoffeeMachine& machine);

    float getVolume() const;
    bool grindGrains(float amount);
    void cleanGrainsContainer();
    void cleanWasteContainer();
    void fillGrains(float amount);
    void showStatus() const;

private:
    const float maxGrainsVolume = 10.0f;
    float currentGrainsVolume = 0.0f;
    const float maxWasteVolume = 5.0f;
    float currentWasteVolume = 0.0f;
    
};
