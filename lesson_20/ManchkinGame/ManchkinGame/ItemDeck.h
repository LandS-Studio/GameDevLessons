#pragma once
#include <fstream>
#include <sstream>

#include "Item.h"
#include "DeckBase.h"
#include <vector>

class ItemDeck : public DeckBase<Item> {
public:
	/*
	ItemDeck() {
		m_database = {
			new Weapon{"The Sword of DOOM", 5},
			new UndeadWeapon{"Stinky knife", 2},
			new HolySword{"Holy Sword", 4},
			new MagicWeapon{"HOLLY MOLLY", 4}
		};
	}
	*/

	ItemDeck() {
		loadItemsFromFile("items_database.txt");
	}
	
	std::vector<Item*> generateItems() {
		std::vector<Item*> items;
		m_availableItems = m_database;
		for (int i = 0; i < 1; ++i) {
			if (!m_availableItems.empty()) {
				items.push_back(generateItem());
			}
		}
		return items;
	}
private:
	void loadItemsFromFile(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Failed to open file: " << filename << std::endl;
			return;
		}

		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string type, name;
			int power;
			
			std::getline(iss, type, ';');
			std::getline(iss, name, ';');
			iss >> power;

			if (type == "Weapon") {
				m_database.push_back(new Weapon(name, power));
			}
			else if (type == "UndeadWeapon") {
				m_database.push_back(new UndeadWeapon(name, power));
			}
			else if (type == "HolySword") {
				m_database.push_back(new HolySword(name, power));
			}
			else if (type == "MagicWeapon") {
				m_database.push_back(new MagicWeapon(name, power));
			}
		}
	}
};