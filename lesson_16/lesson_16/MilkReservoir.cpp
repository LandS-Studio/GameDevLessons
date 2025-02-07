#include "MilkReservoir.h"
#include <iostream>

//TODO UPDATED: Implement getCurrentDay() and getMilkFillingDate() methods for checking milk freshness
int MilkReservoir::getCurrentDay(){
    
    const std::time_t now = std::time(nullptr);
    const std::tm* tmObj = std::localtime(&now);
    return tmObj->tm_yday;
    
}

int MilkReservoir::getMilkFillingDate(){
    
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

void MilkReservoir::showOperations(){
    
    std::cout << "\n--- Current milk level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Clean reservoir\n";
    std::cout << "2. Fill up with milk\n";
    std::cout << "3. Back to main\n";
    
}

void MilkReservoir::receiveInput(){
    
    //TODO, general: Validate input
    std::cout << "Choice: ";
    std::cin >> m_Operation;
    
}

void MilkReservoir::update(){
    
    switch (m_Operation) {
    case 1:
        cleanReservoir();
        break;
    case 2:
        {
            float newVolume = 0.0f;
            std::cout << "Filling...";
            std::cout << "How much have you filled up? (Max: " << MaxVolume << "l) ";
            std::cin >> newVolume;
            
            fill(newVolume);
            
            std::cout << std::endl;
            break;
        }
    case 3:
    default:
        break;
    }
    
}

void MilkReservoir::fill(float volume){
    m_Volume = std::min(m_Volume + volume, MaxVolume);
    std::ofstream file(LAST_FILL_MILK_DATE_FILE, std::ios::trunc);
    if (file.is_open()){
        file << getCurrentDay();
        std::cout << "Milk reservoir filled up to " << m_Volume << "l";
        std::cout << std::endl;
    } else {
        std::cerr << "Error opening file for writing";
        std::cout << "Milk not filled";
        std::cout << std::endl;
    }
}

void MilkReservoir::useMilk(float volume){
    
    m_Volume = std::max(m_Volume - volume, 0.0f);
    
}

// TODO UPDATED: Implement cleanReservoir() method to reset milk volume and last fill date
void MilkReservoir::cleanReservoir(){
    
    m_Volume = 0.0f;
    std::ofstream file(LAST_FILL_MILK_DATE_FILE, std::ios::trunc);
    if (file.is_open()){
        file.close();
        std::cout << "Milk reservoir cleaned";
    } else {
        std::cerr << "Error opening file for writing";
    }
    std::cout << std::endl;
    
}

float MilkReservoir::getVolume(){
    
    return m_Volume;
    
}

//TODO UPDATED: Implement MilkSpoiled logic to check if milk is spoiled
bool MilkReservoir::isMilkSpoiled() {
    int lastdate = getMilkFillingDate();
    if (lastdate == -1) return false;
    int today = getCurrentDay();
    return today - lastdate > 7;
}