#include "MilkReservoir.h"
#include <iostream>

int MilkReservoir::getCurrentDay() const{
    
    const std::time_t now = std::time(nullptr);
    const std::tm* tmObj = std::localtime(&now);
    return tmObj->tm_yday;
    
}

int MilkReservoir::getMilkFillingDate() const{
    
    std::ifstream file(LAST_FILL_MILK_DATE_FILE);
    if (file.is_open()){
        int day = -1;
        file >> day;
        file.close();
        return day;
    } else {
        std::cerr << "Error: Could not open file for reading: " << LAST_FILL_MILK_DATE_FILE << std::endl;
        return -1; 
    }
    
}

void MilkReservoir::fill(float volume){
    currenVolume = std::min(currenVolume + volume, maxVolume);
    std::ofstream file(LAST_FILL_MILK_DATE_FILE, std::ios::trunc);
    if (file.is_open()){
        file << getCurrentDay();
        std::cout << "Milk reservoir filled up to " << currenVolume << "l";
        std::cout << std::endl;
    } else {
        std::cerr << "Error opening file for writing";
        std::cout << "Milk not filled";
        std::cout << std::endl;
    }
}

void MilkReservoir::use(float volume){
    currenVolume = std::max(currenVolume - volume, 0.0f);
}

void MilkReservoir::clean(){
        currenVolume = 0.0f;
    std::ofstream file(LAST_FILL_MILK_DATE_FILE, std::ios::trunc);
    if (file.is_open()){
        file.close();
        std::cout << "Milk reservoir cleaned";
    } else {
        std::cerr << "Error opening file for writing";
    }
    std::cout << std::endl;
    }

bool MilkReservoir::isMilkSpoiled() const {
    if (getMilkFillingDate() == -1) return false;
    return getCurrentDay() - getMilkFillingDate() > spoilDays;
}

void MilkReservoir::showStatus() const {
    std::cout << "Milk reservoir: " << currenVolume << "l / " << maxVolume << "l" << std::endl;
    if (getVolume() > 0){
        if (isMilkSpoiled()){
            std::cout << "Milk is spoiled!" << std::endl;
        } else {
            std::cout << "Milk is fresh!" << std::endl;
        }
    }
}