#include <iostream>

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {

}

Ice::Ice(const Ice &other) : AMateria(other) {

}

Ice	&Ice::operator=(const Ice &other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice(void) {

}

Ice	*Ice::clone(void) const {
	return new Ice(*this);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	AMateria::use(target);
}
