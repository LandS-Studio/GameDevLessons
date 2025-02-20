#pragma once
#include "Tea.h"

class BlackTea : public Tea {
public:
    void showInfo() const override;
    bool checkResources(CoffeeMachine& context) const override;
    void prepare(CoffeeMachine& context) override;
private:
    const float waterNeeded = 0.2f;
    const float requiredTemperature = 95.0f;
};
