#pragma once
#include <vector>
#include <iostream>

#include "WaterReservoir.h"
#include "DrinkProgram.h"
#include "MilkReservoir.h"

class CoffeeGrainsContainer
{
    //not used yet
};


enum class CoffeeMachineState
{
    Sleep,
    PowerOffRequest,
    
    MainMenu,
    
    WaterReservoir,
    MilkReservoir,   //TODO UPDATED: Implement MilkReservoir 

    DrinkSelection,
    DrinkPreparation,

    LowWaterError,
    LowMilkError,    //TODO UPDATED: Implement LowMilkError
    SpoiledMilkError    //TODO UPDATED: Implement SpoiledMilk
};


class CoffeeMachine
{
public:
    ~CoffeeMachine() 
    {
        //TODO HW: clear recipes memory from vector}
        for (auto recipe : m_recipes)
        {
            delete recipe;
        }
    }

    bool IsBooted() const { return !m_powerOffRequest; }

    void initDefaultDrinks();
    void addDrinkReceipt(DrinkProgram* program) { m_recipes.push_back(program); }

    void showMenu();
    void receiveInput();
    void update();

private:
    void powerOn();
    void powerOff();

    void selectNewMenuFromMain();
    
    void showListOfDrinks();
    void prepareDrink();
    void selectDrink();

    void showLowWaterError();
    void showLowMilkError();    //TODO UPDATED: Implement showLowMilkError
    void showSpoiledMilkError();    //TODO UPDATED: Implement showSpoiledMilkError

private:
    std::vector<DrinkProgram*> m_recipes;
    DrinkProgram* m_SelectedDrink = nullptr;

    WaterReservoir m_waterReservoir;
    MilkReservoir m_milkReservoir;    //TODO UPDATED: Implement MilkReservoir logic
    
    int m_currentChoice = -1;
    CoffeeMachineState m_currentState = CoffeeMachineState::Sleep;

    bool m_powerOffRequest = false;

private:
    friend class DrinkProgram;
};