#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>

class MilkReservoir
{
    //TODO HW: Need to implement MilkReservoir logic to be able to prepare Cappuccino
    //See WaterReservoir for reference, the logic here will be very similar
public:
    void showOperations();
    void receiveInput();
    void update();

    void fill(float volume);
    void useMilk(float volume);
    float getVolume();

    void cleanReservoir();
    
    //TODO UPDATE: Implement MilkSpoiled logic to check if milk is spoiled
    bool isMilkSpoiled();

private:
    //TODO UPDATED: Implement getCurrentDay() and getMilkFillingDate() methods to get current day and last milk filling date 
    int getCurrentDay();
    int getMilkFillingDate();
    
    //TODO UPDATED: Implement LAST_FILL_MILK_DATE_FILE constant to store last milk filling date
    const std::string LAST_FILL_MILK_DATE_FILE = "last_milk_fill_date.txt";
    
    int m_Operation = -1;

    float m_Volume = 0.0f;
    const float MaxVolume = 2.0f;

};
