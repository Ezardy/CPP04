#ifndef EX00_DOG_HPP
# define EX00_DOG_HPP

# include "Animal.hpp"

class Dog : Animal {
public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog(void);

	void	makeSound(void) const;
};

#endif
