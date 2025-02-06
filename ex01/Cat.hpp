#ifndef EX01_CAT_HPP
# define EX01_CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat(void);

	void	makeSound(void) const;
	const std::string	&meowThroughTranslator(void);
private:
	Brain	*brain;
};

#endif
