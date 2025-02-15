#pragma once
#include "Reservoir.h"

class WaterReservoir : public Reservoir {
public:
    void clean() override;
    void fill(float volume) override;
    void use(float volume) override;
    void showStatus() const override;
    
    float getVolume() const override { return currenVolume; }
    float getMaxVolume() const override { return maxVolume; }
    std::string getName() const override { return reservoirName; }

private:
    float const maxVolume = 2.0f;
    float currenVolume = 0.0f;
    std::string reservoirName = "WATER";
};
