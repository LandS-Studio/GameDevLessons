#pragma once
#include <string>
#include "Monster.h"
#include "Munchkin.h"

class Modifier {
public:
	virtual void apply(Munchkin* munchkin, Monster* monster) = 0;
	virtual int getMunchkinModifier() const { return m_munchkinPowerChange; }
	virtual int getMonsterModifier() const { return m_monsterPowerChange; }
	virtual int getBonus(int m_munchkinPower) const { return m_munchkinPowerChange + m_monsterPowerChange; }

	virtual std::string getFullInfo() const { return ""; }

protected:
	int m_munchkinPowerChange = 0;
	int m_monsterPowerChange = 0;
};

class SimpleModifier : public Modifier {
public:
	SimpleModifier(int powerBoost) : m_powerBoost(powerBoost) {}

	void apply(Munchkin*, Monster*) override {
		m_munchkinPowerChange = m_powerBoost;
	}

	int getBonus(int m_munchkinPower) const override { return m_powerBoost; }

	virtual std::string getFullInfo() const{
		return "Munchkin power + " + std::to_string(m_powerBoost);
	}

private:
	int m_powerBoost;
};

class DoubleMunchkinLevel : public Modifier
{
public:
	void apply(Munchkin* munchkin, Monster*) override {
		m_munchkinPowerChange = munchkin->getLevel() * 2;
	}

	int getBonus(int m_munchkinPower) const override { return m_munchkinPower; }

	std::string getFullInfo() const override {
		return "Double Munchkin level!";
	}
};

//TASK "f" - Modifiers other types
class HalvesMonsterLevel : public Modifier
{
public:
	//cut monster's power in 2 if he is of type tribe

	HalvesMonsterLevel(Tribe tribe) : m_tribe(tribe) {}
	void apply(Munchkin*, Monster* monster) override {
		if (monster->getTribe() == m_tribe) {
			m_monsterPowerChange = (monster->getLevel() / 2) * -1;
		}
	}

	std::string getFullInfo() const override {
		return "Halvest the level of " + tribeToString(m_tribe) + " monster!";
	}
private:
	Tribe m_tribe;

	std::string tribeToString(Tribe tribe) const {
		switch (tribe) {
		case Tribe::Human:
			return "HUMAN";
		case Tribe::Zombie:
			return "ZOMBIE";
		case Tribe::Undead:
			return "UNDEAD";
		case Tribe::God:
			return "GOD";
		default:
			return "Unknown";
		}
	}
};

//Added unique modifier munchkin/monster specific
//Absolutely unique (for example add Munckin class: gnome, elph, human, sex: man, woman, non-binary
class UniqueModifier : public Modifier
{
public:
	UniqueModifier(int warriorBonus, int thiefBonus, int wizardBonus, int elfBonus) 
		: m_warriorBonus(warriorBonus), m_thiefBonus(thiefBonus), m_wizardBonus(wizardBonus), m_elfBonus(elfBonus) {}

	void apply(Munchkin* munchkin, Monster* monster) override {
		switch (munchkin->getClassType()) {
			case ClassType::Warrior:
				m_munchkinPowerChange += m_warriorBonus;
				break;
			case ClassType::Thief:
				m_munchkinPowerChange += m_thiefBonus;
				break;
			case ClassType::Wizard:
				m_munchkinPowerChange += m_wizardBonus;
				break;
			case ClassType::Elf:
				m_munchkinPowerChange += m_elfBonus;
				break;
			default:
				m_munchkinPowerChange = 0;
				break;
		}
	}

	std::string getFullInfo() const override {
		return "Bonus for: WARRIOR + " + std::to_string(m_warriorBonus) + ", THIEF + " + std::to_string(m_thiefBonus) + ", WIZARD + " + std::to_string(m_wizardBonus) + ", ELF + " + std::to_string(m_elfBonus);
	}
	
private:
	int m_warriorBonus;
	int m_thiefBonus;
	int m_wizardBonus;
	int m_elfBonus;
	
};