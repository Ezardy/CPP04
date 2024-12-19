#include "AMateria.hpp"

AMateria::AMateria(void) : owned(false) {

}

AMateria::AMateria(const AMateria &other) : type(other.type), owned(false) {

}

AMateria::AMateria(const std::string &type) : type(type), owned(false) {

}

AMateria	&AMateria::operator=(const AMateria &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria(void) {

}

const std::string	&AMateria::getType(void) const {
	return type;
}

void	AMateria::use(ICharacter &target) {
	(void)target;
	delete this;
}

void	AMateria::setOwned(void) {
	owned = true;
}

void	AMateria::unsetOwned(void) {
	owned = false;
}

bool	AMateria::isOwned(void) const {
	return owned;
}
