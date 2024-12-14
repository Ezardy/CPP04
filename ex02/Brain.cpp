#include <iostream>
#include <cstdlib>

#include "Brain.hpp"

Brain::Brain(void) : ideaIndex(0) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string tmp_s;

	tmp_s.reserve(10);

	for (int j = 0; j < 100; j += 1) {
		for (int i = 0; i < 10; i += 1) {
			tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
		}
		ideas[j] = tmp_s;
	}
	std::cout << "Brain default constructor was called\n";
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor was called\n";
	*this = other;
}

Brain	&Brain::operator=(const Brain &other) {
	if (this != &other) {
		ideaIndex = other.ideaIndex;
		for (int i = 0; i < 100; i += 1)
			ideas[i] = other.ideas[i];
		std::cout << "Brain copy assignment was called\n";
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor was called\n";
}

const std::string	&Brain::getIdea(void) {
	const std::string	&idea = ideas[ideaIndex++];
	ideaIndex %= 100;
	return idea;
}
