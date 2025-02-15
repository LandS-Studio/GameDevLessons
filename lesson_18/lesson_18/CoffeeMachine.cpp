#include "CoffeeMachine.h"
#include "Cappuccino.h"
#include "Espresso.h"
#include "GreenTea.h"
#include "BlackTea.h"
#include "StateIdle.h"

CoffeeMachine::CoffeeMachine() {
    m_reservoirs.emplace_back(std::make_unique<WaterReservoir>());
    m_reservoirs.emplace_back(std::make_unique<MilkReservoir>());
    m_currentState = std::make_unique<StateIdle>();
    m_powerOffRequest = false;
}

CoffeeMachine::~CoffeeMachine() {
    for (auto recipe : m_recipes) {
        delete recipe;
    }
}

void CoffeeMachine::initDefaultDrinks() {
    m_recipes.push_back(new Espresso());
    m_recipes.push_back(new Cappuccino());
    m_recipes.push_back(new GreenTea());
    m_recipes.push_back(new BlackTea());
}

void CoffeeMachine::showListOfDrinks() const
{
    for (int i = 0; i < m_recipes.size(); ++i) {
        std::cout << i + 1 << ". ";
        m_recipes[i]->showInfo();
    }
}

void CoffeeMachine::prepareDrink(int index) {
    if (index < 1 || index > m_recipes.size()) {
        std::cout << "Invalid choice!" << std::endl;
        return;
    }
    if (checkCleaningRequired()) {
        return;
    }

    DrinkProgram* drink = m_recipes[index - 1];
    if (drink->checkResources(*this)) {
        drink->prepare(*this);
        ++m_prepararionsSinceLastCleaning;
    } else {
        std::cout << std::endl;
    }
}

void CoffeeMachine::setState(std::unique_ptr<CoffeeMachineState> newState) {
    m_currentState = std::move(newState);
}

WaterReservoir& CoffeeMachine::getWaterReservoir() {
    return static_cast<WaterReservoir&>(*m_reservoirs[0]);
}

MilkReservoir& CoffeeMachine::getMilkReservoir() {
    return static_cast<MilkReservoir&>(*m_reservoirs[1]);
}

float CoffeeMachine::getWaterReservoirVolume() const {
    return m_reservoirs[0]->getVolume();
}

float CoffeeMachine::getMilkReservoirVolume() const {
    return m_reservoirs[1]->getVolume();
}

float CoffeeMachine::getGrainsContainerVolume() const {
    return m_grainsContainer.getVolume();
}

void CoffeeMachine::useWater(float amount) {
    m_reservoirs[0]->use(amount);
}

void CoffeeMachine::useMilk(float amount) {
    m_reservoirs[1]->use(amount);
}

void CoffeeMachine::useGrains(float amount) {
    m_grainsContainer.grindGrains(amount);
}

void CoffeeMachine::showMenu() {
    m_currentState->showMenu(*this);
}

void CoffeeMachine::receiveInput() {
    m_currentState->receiveInput(*this);
}

void CoffeeMachine::update() {
    m_currentState->update(*this);
}

void CoffeeMachine::showReservoirStatus(size_t index) const{
    std::cout << "Reservoir " << m_reservoirs[index]->getName() << ": ";
    m_reservoirs[index]->showStatus();
}

void CoffeeMachine::showMachineStatus() {
    for (size_t i = 0; i < m_reservoirs.size(); ++i){
        showReservoirStatus(i);
    }
    m_grainsContainer.showStatus();
}

void CoffeeMachine::powerOn() {
    std::cout << "Grrrrrr.... Welcome to the Coffee Machine!" << std::endl;
    std::cout << "Initializing default drinks..." << std::endl;
    m_powerOffRequest = false;
    showMachineStatus();
}

void CoffeeMachine::powerOff() {
    std::cout << "Grrrrrr.... Bye-bye... (Cool animation's playing)\n\n\n";
    m_powerOffRequest = true;
}

void CoffeeMachine::cleanMachine() {
    std::cout << "Cleaning the machine..." << std::endl;
    for (auto& reservoir : m_reservoirs) {
        reservoir->clean();
    }
    m_grainsContainer.cleanWasteContainer();
    m_prepararionsSinceLastCleaning = 0;
    std::cout << "Machine cleaned!" << std::endl;
}

bool CoffeeMachine::checkCleaningRequired() {
    if (m_prepararionsSinceLastCleaning >= m_cleaningInterval) {
        std::cout << "Machine requires cleaning!" << std::endl;
        cleanMachine();
        return true;
    }
    return false;
}



//TODO: Update activity and sleep mode
/*
void CoffeeMachine::updateActivity() {
    m_lastActivityTime = std::chrono::steady_clock::now();
    m_isSleeping = false;
}

void CoffeeMachine::checkSleepMode() {
    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::minutes>(now - m_lastActivityTime).count();
    if (duration >= 5 && !m_isSleeping) {
        m_isSleeping = true;
        std::cout << "Coffee machine is going to sleep..." << std::endl;
    }
}

void CoffeeMachine::wakeUp() {
    if (m_isSleeping) {
        std::cout << "Coffee machine is waking up..." << std::endl;
        m_isSleeping = false;
        updateActivity();
    } else {
        std::cout << "Coffee machine is already awake!" << std::endl;
    }
}
*/
