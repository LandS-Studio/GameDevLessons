#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>

#include "Reservoir.h"

class MilkReservoir : public Reservoir {
public:
    bool isMilkSpoiled() const;
    
    void clean() override;
    void fill(float volume) override;
    void use(float volume) override;
    void showStatus() const override;
        
    float getVolume() const override { return currenVolume; }
    float getMaxVolume() const override { return maxVolume; }
    std::string getName() const override { return reservoirName; }

private:
    int getCurrentDay() const;
    int getMilkFillingDate() const;

    const std::string LAST_FILL_MILK_DATE_FILE = "last_milk_fill_date.txt";
    const int spoilDays = 5;
    
    float const maxVolume = 1.0f;
    float currenVolume = 0.0f;
    std::string reservoirName = "MILK";
};
