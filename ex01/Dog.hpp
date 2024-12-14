#ifndef EX00_DOG_HPP
# define EX00_DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog(void);

	void	makeSound(void) const;
	const std::string	&barkThroughTranslator(void);
private:
	Brain	*brain;
};

#endif
