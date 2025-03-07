#pragma once
#include "DeckBase.h"
#include "Modifier.h"
#include <vector>

class ModifierDeck : public DeckBase<Modifier>{
public:
	ModifierDeck() {
		m_database = {
			{new SimpleModifier{3}},
			{new SimpleModifier{3}},
			{new SimpleModifier{2}},
			{new SimpleModifier{2}},
			{new SimpleModifier{2}},
			{new SimpleModifier{4}},
			{new SimpleModifier{1}},
			{new SimpleModifier{1}},
			{new SimpleModifier{1}},
			{new DoubleMunchkinLevel{}},
			{new DoubleMunchkinLevel{}},
			{new HalvesMonsterLevel{Tribe::Undead}},
			{new HalvesMonsterLevel{Tribe::God}},
			{new UniqueModifier(1, 2, 3, 4)},
			{new UniqueModifier(1, 2, 3, 4)}
		};
	}

	std::vector<Modifier*> generateModifiers() {
		std::vector<Modifier*> result;
		m_availableItems = m_database;
		for (int i = 0; i < 5; ++i) {
			if (!m_availableItems.empty()) {
				result.push_back(generateItem());
			}
		}
		return result;
	}
};