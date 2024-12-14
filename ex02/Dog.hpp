#ifndef EX01_DOG_HPP
# define EX01_DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
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
