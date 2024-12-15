#include "AMateria.hpp"

AMateria::AMateria(void) {

}

AMateria::AMateria(const AMateria &other) : type(other.type) {

}

AMateria::AMateria(const std::string &type) : type(type) {

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
