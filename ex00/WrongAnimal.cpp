#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor was called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy constructor was called\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		std::cout << "WrongAnimal copy assignment was called\n";
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor was called\n";
}

WrongAnimal::WrongAnimal(const std::string type) : type(type) {
	std::cout << "WrongAnimal constructor was called\n";
}
