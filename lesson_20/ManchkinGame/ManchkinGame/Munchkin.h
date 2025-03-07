#pragma once
#include <vector>
#include <string>
#include <iostream>

class Item;
class Modifier;

using uint = unsigned int;

enum class ClassType {
	Warrior,
	Thief,
	Wizard,
	Elf
};

class Munchkin
{
public:
	Munchkin() = default;
	Munchkin(const std::string& name, ClassType classType) : m_name(name), m_classType(classType) {}

	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	void setClassType(int choice) {
		switch (choice) {	
			case 1:
				m_classType = ClassType::Warrior;
				break;
			case 2:
				m_classType = ClassType::Thief;
				break;
			case 3:
				m_classType = ClassType::Wizard;
				break;
			case 4:
				m_classType = ClassType::Elf;
				break;
			default:
				break;
		}
	}

	ClassType getClassType() const {
		return m_classType;
	}

	std::string classToString() const
	{
		switch (m_classType)
		{
			case ClassType::Warrior:
				return "Warrior";
			case ClassType::Thief:
				return "Thief";
			case ClassType::Wizard:
				return "Wizard";
			case ClassType::Elf:
				return "Elf";
		}
	}
	
	void printAllClassType() const {
		for (int i = static_cast<int>(ClassType::Warrior); i <= static_cast<int>(ClassType::Elf); ++i) {
			ClassType classType = static_cast<ClassType>(i);
			switch (classType) {
			case ClassType::Warrior:
				std::cout << "1.Warrior" << std::endl;
				break;
			case ClassType::Thief:
				std::cout << "2.Thief" << std::endl;
				break;
			case ClassType::Wizard:
				std::cout << "3.Wizard" << std::endl;
				break;
			case ClassType::Elf:
				std::cout << "4.Elf" << std::endl;
				break;
			default:
				break;
			}
		}
	}

	int getLevel() const { return m_level; } // used by FIGHT
	void updateLevelBy(int levels);	//used by VICTORY FLOW

	void addItem(Item* item);
	void addItems(const std::vector<Item*>& items);
	const std::vector<Item*>& getItems() const;
	
	Modifier* popModifier(int idx);
	const std::vector<Modifier*>& getModifiers() const { return m_modifiers; }	//FOR UI ONLY
	void addModifier(Modifier* modifier) { m_modifiers.push_back(modifier); }
	void addModifiers(const std::vector<Modifier*>& modifiers) { m_modifiers = modifiers; }

	//Implemented at random
	void removeModifierFromHand();
	void removeItemEquipped();
	void removeBiggestBonusCard();

private:
	uint m_level = 1;
	std::string m_name;
	ClassType m_classType = ClassType::Warrior;

	std::vector<Item*> m_items;
	std::vector<Modifier*> m_modifiers;
};