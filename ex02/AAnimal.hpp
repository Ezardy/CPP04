#ifndef EX01_ANIMAL_HPP
# define EX01_ANIMAL_HPP

# include <string>

class AAnimal {
public:
	AAnimal(void);
	AAnimal(const AAnimal &other);
	AAnimal	&operator=(const AAnimal &other);
	virtual ~AAnimal(void);

	virtual void		makeSound(void) const = 0;
	const std::string	&getType(void) const; 
protected:
	AAnimal(const std::string type);

	const std::string	type;
};

#endif
