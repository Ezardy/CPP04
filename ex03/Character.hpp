#ifndef EX03_CHARACTER_HPP
# define EX03_CHARACTER_HPP

# include <string>

# include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character(void);
	Character(const Character &other);
	Character(const std::string name);
	Character	&operator=(const Character &other);
	~Character(void);

	const std::string	&getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
private:
	void	clearInventory(void);

	AMateria	*inventory[4];
	std::string	name;
};

#endif
