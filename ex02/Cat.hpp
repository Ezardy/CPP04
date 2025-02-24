#ifndef EX02_CAT_HPP
# define EX02_CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
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
