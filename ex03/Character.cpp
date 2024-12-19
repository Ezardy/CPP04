#include "Character.hpp"

Character::Character(void) : inventory(), name("Unnamed") {

}

Character::Character(const Character &other) : inventory() {
	*this = other;
}

Character::Character(const std::string name) : inventory(), name(name) {

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
	if (m && !m->isOwned()) {
		for (int i = 0; i < 4; i += 1) {
			if (!inventory[i]) {
				inventory[i] = m;
				m->setOwned();
				i = 4;
			}
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx]->unsetOwned();
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && inventory[idx]) {
		inventory[idx]->use(target);
		inventory[idx] = NULL;
	}
}

void	Character::clearInventory(void) {
	for (int i = 0; i < 4; i += 1) {
		delete inventory[i];
		inventory[i] = NULL;
	}
}
