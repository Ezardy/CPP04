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
	void				setOwned(void);
	void				unsetOwned(void);
	bool				isOwned(void) const;

	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);
protected:
	std::string	type;
	bool		owned;
};

#endif
