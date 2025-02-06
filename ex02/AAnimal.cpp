#include <iostream>

#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal default constructor was called\n";
}

AAnimal::AAnimal(const AAnimal &other) {
	(void)other;
	std::cout << "AAnimal copy constructor was called\n";
}

AAnimal	&AAnimal::operator=(const AAnimal &other) {
	if (this != &other)
		std::cout << "AAnimal copy assignment was called\n";
	return *this;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor was called\n";
}

AAnimal::AAnimal(const std::string type) : type(type) {
	std::cout << "AAnimal constructor was called\n";
}

const std::string	&AAnimal::getType(void) const {
	return type;
}
