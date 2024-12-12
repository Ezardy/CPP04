#include <iostream>

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor was called\n";
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor was called\n";
}

Animal	&Animal::operator=(const Animal &other) {
	if (this != &other)
		std::cout << "Animal copy assignment was called\n";
	return *this;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor was called\n";
}

Animal::Animal(const std::string type) : type(type) {
	std::cout << "Animal constructor was called\n";
}
