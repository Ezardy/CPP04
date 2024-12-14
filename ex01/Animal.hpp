#ifndef EX01_ANIMAL_HPP
# define EX01_ANIMAL_HPP

# include <string>

class Animal {
public:
	Animal(void);
	Animal(const Animal &other);
	Animal	&operator=(const Animal &other);
	virtual ~Animal(void);

	virtual void		makeSound(void) const;
	const std::string	&getType(void) const; 
protected:
	Animal(const std::string type);

	const std::string	type;
};

#endif
