#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return 0; }
	virtual int getBasePower() const { return 0; }
	virtual bool canDestroyMonster(Tribe monsterTribeModifier) const { return false; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power) : m_power(power)
	{
		setName(name);
	}

	int getBasePower() const override
	{
		return m_power;
	}

	std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)	
		{
		case Tribe::Undead:
			return m_power * 2;
		case Tribe::Human:
		case Tribe::Zombie:
		default:
			return m_power;
		}
	}

	std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

class MagicWeapon : public Weapon
{
public:
	MagicWeapon(const std::string& name, int power) : Weapon(name, power) {}

	int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Human:
			return m_power * 0.8;
		case Tribe::Undead:
		case Tribe::Zombie:
		case Tribe::God:
			return m_power * 2;
		default:
			return m_power;
		}
	}

	std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs GODS BUT x0.8 vs HUMANS!\n";
	}
};

//TASK "b" - HolySword class
class HolySword : public Weapon
{
public:
	HolySword(const std::string& name, int power) : Weapon(name, power) {}

	std::string getFullInfo() const override {
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Instantly destroys a Zombie!\n";
	}

	int getPower(Tribe monsterTribeModifier) const override{
		switch (monsterTribeModifier) {
			case Tribe::Human:
			case Tribe::Undead:
				return m_power * 2;
			case Tribe::Zombie:
			case Tribe::God:
			default:
				return m_power;
		}
	}

	bool canDestroyMonster(Tribe monsterTribeModifier) const override {
		return monsterTribeModifier == Tribe::Zombie;
	}

};