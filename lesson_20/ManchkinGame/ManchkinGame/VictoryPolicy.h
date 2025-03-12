#pragma once
#include "Munchkin.h"
#include "ItemDeck.h"
#include "ModifierDeck.h"

class VictoryPolicy {
public:
    virtual ~VictoryPolicy() = default;
    virtual void apply(Munchkin* munchkin, ItemDeck& itemDeck, ModifierDeck& modifierDeck) = 0;
    virtual std::string getFullInfo() const = 0;
};

class IncreaseLevelVictory : public VictoryPolicy {
public:
    IncreaseLevelVictory(int level) : m_level(level) {}

    void apply(Munchkin* munchkin, ItemDeck& itemDeck, ModifierDeck& modifierDeck) override {
        munchkin->updateLevelBy(m_level);
    }

    std::string getFullInfo() const override {
        return "Increase level by: " + std::to_string(m_level);
    }

private:
    int m_level;
};

class GenerateNewItemsVictory : public VictoryPolicy {
public:
    GenerateNewItemsVictory(int itemCount) : m_itemCount(itemCount) {}

    void apply(Munchkin* munchkin, ItemDeck& itemDeck, ModifierDeck& modifierDeck) override {
        auto newItems = itemDeck.generateItems();
        for (int i = 0; i < m_itemCount; ++i) {
            munchkin->addItem(newItems[i]);
        }
    }

    std::string getFullInfo() const override {
        return "Generate " + std::to_string(m_itemCount) + " new items";
    }

private:
    int m_itemCount;
};

class GenerateNewModifiersVictory : public VictoryPolicy {
public:
    GenerateNewModifiersVictory(int modifierCount) : m_modifierCount(modifierCount) {}

    void apply(Munchkin* munchkin, ItemDeck& itemDeck, ModifierDeck& modifierDeck) override {
        auto newModifiers = modifierDeck.generateModifiers();
        for (int i = 0; i < m_modifierCount; ++i) {
            munchkin->addModifier(newModifiers[i]);
        }
    }

    std::string getFullInfo() const override {
        return "Generate " + std::to_string(m_modifierCount) + " new modifiers";
    }

private:
    int m_modifierCount;
};
