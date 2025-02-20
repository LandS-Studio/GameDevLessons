#include "CoffeeGrainsContainer.h"

#include "CoffeeMachine.h"
#include "StateIdle.h"

void CoffeeGrainsContainer::showMenu(CoffeeMachine& machine) const {
    std::cout << std::endl;
    std::cout << "--- Current GRAINS level: " << currentGrainsVolume << "kg out of " << maxGrainsVolume << "kg max ---" << std::endl;
    std::cout << "--- Current WASTE level: " << currentWasteVolume << "kg out of " << maxWasteVolume << "kg max ---" << std::endl;
    std::cout << "1. Clean GRAINS container" << std::endl;
    std::cout << "2. Fill up with GRAINS" << std::endl;
    std::cout << "3. Clean WASTE container" << std::endl;
    std::cout << "4. Back to main" << std::endl;
}

void CoffeeGrainsContainer::receiveInput(CoffeeMachine& machine) {
    int choice;
    std::cout << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;

    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice!" << std::endl;
        machine.setState(std::make_unique<StateIdle>());
    } else if (choice == 1) {
        cleanGrainsContainer();
    } else if (choice == 2) {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << maxGrainsVolume << "kg) ";
        std::cin >> newVolume;
        fillGrains(newVolume);
    } else if (choice == 3) {
        cleanWasteContainer();
    } else if (choice == 4) {
        std::cout << "Returning to main menu..." << std::endl;
        machine.setState(std::make_unique<StateIdle>());
    }
}

void CoffeeGrainsContainer::update(CoffeeMachine& machine) {
    showMenu(machine);
    receiveInput(machine);
}

float CoffeeGrainsContainer::getVolume() const {
    return currentGrainsVolume;
}

bool CoffeeGrainsContainer::grindGrains(float amount) {
    if (getVolume() < amount) {
        std::cout << "Grinding failed!" << std::endl;
        return false;
    }
    if (currentWasteVolume + amount > maxWasteVolume) {
        std::cout << "Waste container is full! Please clean it." << std::endl;
        return false;
    }

    currentGrainsVolume -= amount;
    currentWasteVolume += amount;
    std::cout << "Grinding coffee grains..." << std::endl;
    return true;
}

void CoffeeGrainsContainer::cleanGrainsContainer() {
    currentGrainsVolume = 0.0f;
    std::cout << "Coffee grains container is cleaned!" << std::endl;
}

void CoffeeGrainsContainer::cleanWasteContainer() {
    currentWasteVolume = 0.0f;
    std::cout << "Waste container is cleaned!" << std::endl;
}

void CoffeeGrainsContainer::fillGrains(float amount) {
    currentGrainsVolume = std::min(currentGrainsVolume + amount, maxGrainsVolume);
    std::cout << "Coffee grains container filled up to " << currentGrainsVolume << "kg" << std::endl;
}

void CoffeeGrainsContainer::showStatus() const {
    std::cout << "Coffee grains container: " << currentGrainsVolume << "kg / " << maxGrainsVolume << "kg" << std::endl;
    std::cout << "Waste container: " << currentWasteVolume << "kg / " << maxWasteVolume << "kg" << std::endl;
}





