#pragma once
#include <vector>
#include <cstdlib>

template<typename T>
class DeckBase {
public:
    virtual ~DeckBase() {
        for (T* item : m_database) {
            delete item;
        }
    }

    T* generateItem() {
        if (m_availableItems.empty()) {
            m_availableItems = m_database;
        }
        int index = std::rand() % m_availableItems.size();
        T* item = m_availableItems[index];
        m_availableItems.erase(m_availableItems.begin() + index);
        return item;
    }

protected:
    std::vector<T*> m_database;
    std::vector<T*> m_availableItems;    
};
