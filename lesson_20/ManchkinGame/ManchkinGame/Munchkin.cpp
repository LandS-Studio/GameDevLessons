#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"

void Munchkin::updateLevelBy(int levels) {
    if (m_level + levels <= 0) {
        m_level = 1;
    } else {
	    m_level += levels; 
    }

}

void Munchkin::addItem(Item* item)
{
    m_items.push_back(item);
}

void Munchkin::addItems(const std::vector<Item*>& items)
{
    m_items = items;
}

const std::vector<Item*>& Munchkin::getItems() const
{
    return m_items;
}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];
    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;
}

void Munchkin::removeItemEquipped()
{
    // TASK "e" - remove item from hand
    // ------------------------------------- //
    //remove item from hand
    if (!m_items.empty()){
        int index = std::rand() % m_items.size();
        m_items.erase(m_items.begin() + index);
    }
    // ------------------------------------- //
}

void Munchkin::removeModifierFromHand()
{
    // TASK "e" - remove modifier from hand
    // ------------------------------------- //
    //remove modifier from hand
    if (!m_modifiers.empty()){
        int index = std::rand() % m_modifiers.size();
        m_modifiers.erase(m_modifiers.begin() + index);
    }
    // ------------------------------------- //
}

void Munchkin::removeBiggestBonusCard()
{
    // TASK "e" - remove biggest bonus card
    // ------------------------------------- //
    //remove modifier with the biggest bonus
    if (!m_modifiers.empty()){
        int index = 0;
        int maxBonus = m_modifiers[0]->getBonus(m_level);
        for (int i = 1; i < m_modifiers.size(); ++i){
            if (m_modifiers[i]->getBonus(m_level) > maxBonus){
                maxBonus = m_modifiers[i]->getBonus(m_level);
                index = i;
            }
        }
        m_modifiers.erase(m_modifiers.begin() + index);
    }
    
    // ------------------------------------- //
}

