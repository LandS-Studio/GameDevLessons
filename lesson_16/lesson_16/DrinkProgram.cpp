#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include <chrono>
#include <thread>

DrinkProgram::DrinkProgram(DrinkType type, CoffeeMachine& context) : 
    m_drinkType(type), 
    m_context(context) {}

void DrinkProgram::showInfo()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
        std::cout << "Espresso!";
        break;
    case DrinkType::Cappuccino:
        std::cout << "Cappuccino!";
        break;
    default:
        break;
    }
}

DrinkProgramStatus DrinkProgram::prepare()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
    {
        //TODO: method prepareEspresso()

        if (m_context.m_waterReservoir.getVolume() < EsspressoVolume)
        {
            return DrinkProgramStatus::LowWater;
        }

        m_context.m_waterReservoir.useWater(EsspressoVolume);

        std::cout << "\n\nGrrr ";

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "\nPreparing... Espresso... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int i = 5; i > 3; i--)
        {
            std::cout << i << ".";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "..Hanging... ";
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::cout << "DONE!\n\n";

        return DrinkProgramStatus::Success;
    }
    case DrinkType::Cappuccino:
        //TODO UPDATED: Implement prepareCappuccino() method with checking milk and water levels and milk spoilage
        if (m_context.m_waterReservoir.getVolume() < CappuccinoWater){
            return DrinkProgramStatus::LowWater;
        }
        if (m_context.m_milkReservoir.getVolume() < CappuccinoMilk){
            return DrinkProgramStatus::LowMilk;
        }
        if (m_context.m_milkReservoir.isMilkSpoiled()) {
            return DrinkProgramStatus::SpoiledMilk;
        }

        m_context.m_waterReservoir.useWater(CappuccinoWater);
        m_context.m_milkReservoir.useMilk(CappuccinoMilk);

        std::cout << "\n\nGrrr ";

        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));

        std::cout << "\nPreparing... Cappuccino... ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        for (int i = 5; i > 3; i--)
        {
            std::cout << i << ".";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "..Hanging... ";
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::cout << "DONE!\n\n";

        return DrinkProgramStatus::Success;
    default:
        break;
    };

    return DrinkProgramStatus::Success;
}