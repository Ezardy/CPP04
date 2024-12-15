#ifndef EX03_MATERIASOURCE_HPP
# define EX03_MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : IMateriaSource {
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource	&operator=(const MateriaSource &other);
	~MateriaSource(void);

	void		learnMateria(AMateria *materia);
	AMateria*	createMateria(const std::string &type);
private:
	void		purgeMaterias(void);

	AMateria	*materias[4];
};

#endif
