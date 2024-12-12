#include <iostream>

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor was called\n";
}

Cat::Cat(const Cat &other) {

}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
		std::cout << "Cat copy constructor was called\n";
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor was called\n";
}

void	Cat::makeSound(void) const {
	std::cout << "Meow";
}
