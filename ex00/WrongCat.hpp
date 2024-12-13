#ifndef EX00_WRONGCAT_HPP
# define EX00_WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	virtual ~WrongCat(void);

	void	makeSound(void) const;
};

#endif
