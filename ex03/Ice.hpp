#ifndef EX03_ICE_HPP
# define EX03_ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &other);
	Ice	&operator=(const Ice &other);
	~Ice(void);

	Ice	*clone(void) const;
	void	use(ICharacter &target);
};

#endif
