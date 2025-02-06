#ifndef EX01_WRONGANIMAL_HPP
# define EX01_WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal	&operator=(const WrongAnimal &other);
	~WrongAnimal(void);

	void				makeSound(void) const;
	const std::string	&getType(void) const; 
protected:
	WrongAnimal(const std::string type);

	const std::string	type;
};

#endif
