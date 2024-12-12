#ifndef EX00_WRONGCAT_HPP
# define EX00_WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat(void);

	void	makeSound(void) const;
};

#endif
