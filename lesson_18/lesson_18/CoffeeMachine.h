#pragma once
#include <memory>
#include <vector>

#include "CoffeeGrainsContainer.h"
#include "DrinkProgram.h"
#include "CoffeeMachineState.h"

#include "WaterReservoir.h"
#include "MilkReservoir.h"

class CoffeeMachineState;

class CoffeeMachine {
public:
    CoffeeMachine();
    ~CoffeeMachine();
    // Returns true if the machine is powered on
    bool IsBooted() const { return !m_powerOffRequest; }

    void initDefaultDrinks();
    void showReservoirStatus(size_t index) const;
    void prepareDrink(int index);
    void setState(std::unique_ptr<CoffeeMachineState> newState);
    void showListOfDrinks() const;

    float getWaterReservoirVolume() const;
    float getMilkReservoirVolume() const;
    float getGrainsContainerVolume() const;

    void useWater(float amount); 
    void useMilk(float amount);
    void useGrains(float amount);

    size_t getRecipesCount() const { return m_recipes.size(); }

    MilkReservoir& getMilkReservoir();
    WaterReservoir& getWaterReservoir();
    CoffeeGrainsContainer& getGrainsContainer() { return m_grainsContainer; }
    
    void showMenu();
    void receiveInput();
    void update();

    void cleanMachine();
    void wakeUp();

    void powerOn();
    void powerOff();

    void showMachineStatus();

private:
    std::vector<DrinkProgram*> m_recipes;
    std::vector<std::unique_ptr<Reservoir>> m_reservoirs;
    std::unique_ptr<CoffeeMachineState> m_currentState;
    CoffeeGrainsContainer m_grainsContainer;

    int m_prepararionsSinceLastCleaning = 0;
    const int m_cleaningInterval = 10;

    bool checkCleaningRequired();
    
    //TODO: Update activity and sleep mode
    /*
    std::chrono::time_point<std::chrono::steady_clock> m_lastActivityTime;
    bool m_isSleeping = false;

    void updateActivity();
    void checkSleepMode();
    */
    bool m_powerOffRequest = true;
};