#include "WaterReservoir.h"
#include <iostream>

void WaterReservoir::clean(){
    currenVolume = 0.0f;
    std::cout << "Water reservoir is cleaned!" << std::endl;
}

void WaterReservoir::fill(float volume){
    currenVolume = std::min(currenVolume + volume, maxVolume);
}

void WaterReservoir::use(float volume){
    currenVolume = std::max(currenVolume - volume, 0.0f);
}

void WaterReservoir::showStatus() const {
    std::cout << "Water reservoir: " << currenVolume << "l / " << maxVolume << "l" << std::endl;
}
