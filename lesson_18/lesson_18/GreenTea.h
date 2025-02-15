#pragma once
#include "Tea.h"

class GreenTea : public Tea {
public:
    void showInfo() const override;
    bool checkResources(CoffeeMachine& context) const override;
    void prepare(CoffeeMachine& context) override;
private:
    const float waterNeeded = 0.2f;
    const float requiredTemperature = 80.0f;
    
};
