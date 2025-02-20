#pragma once
#include "Coffee.h"

class Espresso : public Coffee{
public:
    void showInfo() const override;
    bool checkResources(CoffeeMachine& context) const override;
    void prepare(CoffeeMachine& context) override;
private:
    const float waterNeeded = 0.05f;
    const float grainsNeeded = 0.1f;
};
