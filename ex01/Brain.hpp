#ifndef EX01_BRAIN_HPP
# define EX01_BRAIN_HPP

# include <string>

class Brain {
public:
	Brain(void);
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);
	~Brain(void);

	const std::string	&getIdea(void);
private:
	std::string		ideas[100];
	unsigned int	ideaIndex;
};

#endif
