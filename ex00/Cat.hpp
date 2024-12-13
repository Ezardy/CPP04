#ifndef EX00_CAT_HPP
# define EX00_CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat(void);

	void	makeSound(void) const;
};

#endif
