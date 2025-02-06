#ifndef EX03_CURE_HPP
# define EX03_CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &other);
	Cure	&operator=(const Cure &other);
	~Cure(void);

	Cure	*clone(void) const;
	void	use(ICharacter &target);
};

#endif
