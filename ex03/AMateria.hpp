#ifndef EX03_AMATERIA_HPP
# define EX03_AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria {
public:
	AMateria(void);
	AMateria(const AMateria &other);
	AMateria(const std::string &type);
	AMateria	&operator=(const AMateria &other);
	virtual ~AMateria(void);

	const std::string	&getType(void) const;

	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target) = 0;
protected:
	std::string	type;
};
#endif
