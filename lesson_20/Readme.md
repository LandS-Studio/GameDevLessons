# Домашнє завдання МАНЧКІН

## Реалізовані завдання

### a. Реалізувано функцію std::string RunawayPolicy::getFullInfo() та розширено UI для виводу повної інформації про монстра

std::string getFullInfo() const { 
	return "Monster \"" + getName() + "\", level " + std::to_string(getLevel()) + ". " + m_RunawayPolicy->getFullInfo(); 
}

std::string Runaway::getFullInfo() {
	return "You are dead! (level is dropped to 1, will lose 3 cards from hand)";
} і т.д.

### b. Додано новий Item з новими здібностями. Н-д: “Holy Sword”, який одразу знищує Zombie

Додано зброю з прикладу

### c. Реалізувано методи MonsterDeck::generateMonster(), ModifierDeck::generateModifier(), ItemDeck::generateItems(), які повертають щоразу випадковий/випадкові, проте унікальний/унікальні предмет/-и(який ще не розігрувався у грі)

std::vector<Modifier*> generateModifiers() {
	std::vector<Modifier*> result;
	m_availableItems = m_database;
	for (int i = 0; i < 5; ++i) {
		if (!m_availableItems.empty()) {
			result.push_back(generateItem());
		}
	}
	return result;
} і т.д.

### e. Реалізувано заготовки нових RunawayPolicy: Runaway_ItemEquipedRemoval, Runaway_ModifierFromHandRemoval, Runaway_BiggestBonusCardRemoval

### f. Реалізувано заготовки Modifier’ів інших типів

Додано нові модифікатори типу class UniqueModifier : public Modifier, який дає бонус відповідно до типу класа гравця який вибирається на початку

### g. Об’єднано дубльований код в MonsterDeck::generateMonster(), ModifierDeck::generateModifier(), ItemDeck::generateItems(), використано наслідування, шляхом об’єднання під одну ієрархію DeckBase

### h. Реалізувано VictoryPolicy
Додано підвищення рівня гравця 
Додано генерацію випадкових айтемів 
Додано генерацію випадкових модифікаторів 
Додано вибір випадкового VictoryPolicy після перемоги

### i. Перенесено базу даних айтемів у файл у форматі “type;name; params for the type” у окремий файл items_database.txt





