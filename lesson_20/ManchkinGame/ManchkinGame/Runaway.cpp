#include "Runaway.h"
#include "Munchkin.h"

void Runaway_LevelDowngrade::apply(Munchkin* munchkin){
	munchkin->updateLevelBy(-m_levelToDowngrade);
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin){
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply){
		Runaway_LevelDowngrade::apply(munchkin);
	}
}

void Runaway_ItemEquipedRemoval::apply(Munchkin* munchkin) {
	munchkin->removeItemEquipped();
}

void Runaway_BiggestBonusCardRemoval::apply(Munchkin* munchkin) {
	munchkin->removeBiggestBonusCard();
}

void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin) {
	munchkin->removeModifierFromHand();
}


// TASK "a" - Runaway policy getFullInfo()
// ------------------------------------- //
std::string Runaway::getFullInfo() {
	return "You are dead! (level is dropped to 1, will lose 3 cards from hand)";
}

std::string Runaway_LevelDowngrade::getFullInfo() {
	return "You are dead! (level is dropped to " + std::to_string(m_levelToDowngrade) + ")";
}

std::string Runaway_LevelDowngradeIf::getFullInfo() {
	return "You are dead! (level is dropped to " + std::to_string(m_levelToDowngrade) + " if you are level " + std::to_string(m_minimalMunchkinLevelToApply) + " or higher)";
}

std::string Runaway_ItemEquipedRemoval::getFullInfo() {
	return "You are dead! (will lose 1 item from hand)";
}

std::string Runaway_BiggestBonusCardRemoval::getFullInfo() {
	return "You are dead! (will lose the item with the biggest bonus)";
}

std::string Runaway_ModifierFromHandRemoval::getFullInfo() {
	return "You are dead! (will lose 1 modifier from hand)";
}
// ------------------------------------- //