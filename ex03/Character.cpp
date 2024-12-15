#include "Character.hpp"

Character::Character(void) : inventory(), name("Unnamed") {

}

Character::Character(const Character &other) {
	*this = other;
}

Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		name = other.name;
		clearInventory();
		for (int i = 0; i < 4; i += 1) {
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character(void) {
	clearInventory();
}

const std::string	&Character::getName() const {
	return name;
}

void	Character::equip(AMateria* m) {
	if (m) {
		for (int i = 0; i < 4; i += 1) {
			if (!inventory[i]) {
				inventory[i] = m;
				i = 4;
			}
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4)
		inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx]->use(target);
		delete inventory[idx];
		inventory[idx] = NULL;
	}
}

void	Character::clearInventory(void) {
	for (int i = 0; i < 4; i += 1) {
		delete inventory[i];
		inventory[i] = NULL;
	}
}
