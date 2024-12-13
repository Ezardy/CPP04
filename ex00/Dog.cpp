#include <iostream>

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor was called\n";
}

Dog::Dog(const Dog &other) : Animal("Dog") {
	(void)other;
	std::cout << "Dog copy constructor was called\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
		std::cout << "Dog copy assignment was called\n";
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor was called\n";
}

void	Dog::makeSound(void) const {
	std::cout << "Bark";
}
