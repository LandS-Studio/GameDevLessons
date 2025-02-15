#pragma once
#include "Coffee.h"

class Cappuccino : public Coffee {
public:
    void showInfo() const override;
    bool checkResources(CoffeeMachine& context) const override;
    void prepare(CoffeeMachine& context) override;
private:
    const float waterNeeded = 0.1f;
    const float milkNeeded = 0.15f;
    const float grainsNeeded = 0.2f;
};
