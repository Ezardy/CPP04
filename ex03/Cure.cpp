#include <iostream>

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {

}

Cure::Cure(const Cure &other) : AMateria(other) {

}

Cure	&Cure::operator=(const Cure &other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure(void) {

}

Cure	*Cure::clone(void) const {
	return new Cure(*this);
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
