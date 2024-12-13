#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor was called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal("WrongCat") {
	(void)other;
	std::cout << "WrongCat copy constructor was called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		std::cout << "WrongCat copy assignment was called\n";
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor was called\n";
}

void	WrongCat::makeSound(void) const {
	std::cout << "Meow";
}
