#include <iostream>

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor was called\n";
}

Dog::Dog(const Dog &other) : AAnimal("Dog"), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor was called\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		delete brain;
		brain = new Brain(*other.brain);
		std::cout << "Dog copy assignment was called\n";
	}
	return *this;
}

Dog::~Dog(void) {
	delete brain;
	std::cout << "Dog destructor was called\n";
}

void	Dog::makeSound(void) const {
	std::cout << "Bark";
}

const std::string	&Dog::barkThroughTranslator(void) {
	return brain->getIdea();
}
