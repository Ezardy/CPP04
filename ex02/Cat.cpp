#include <iostream>

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), brain(new Brain()) {
	std::cout << "Cat default constructor was called\n";
}

Cat::Cat(const Cat &other) : AAnimal("Cat"), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor was called\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		delete brain;
		brain = new Brain(*other.brain);
		std::cout << "Cat copy assignment was called\n";
	}
	return *this;
}

Cat::~Cat(void) {
	delete brain;
	std::cout << "Cat destructor was called\n";
}

void	Cat::makeSound(void) const {
	std::cout << "Meow";
}

const std::string	&Cat::meowThroughTranslator(void) {
	return brain->getIdea();
}
