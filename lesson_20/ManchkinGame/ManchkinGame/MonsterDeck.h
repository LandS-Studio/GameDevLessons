#pragma once
#include <vector>
#include "DeckBase.h"
#include "Monster.h"

class Monster;

class MonsterDeck : public DeckBase<Monster> {
public:
	MonsterDeck() {
		m_database = {
			//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
			new Monster{"Crazy Joe", 10, Tribe::Zombie},
			new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
			new Monster{"Vampire", 15, Tribe::Undead, new Runaway_LevelDowngrade{1}}
		};
	}

	Monster* generateMonster() {
		return generateItem();
	}
};