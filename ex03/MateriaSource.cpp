#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : materias() {

}

MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		purgeMaterias();
		for (int i = 0; i < 4; i += 1) {
			if (other.materias[i])
				materias[i] = other.materias[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < 4; i += 1) {
		if (!materias[i])
			materias[i] = materia;
	}
}

void	MateriaSource::purgeMaterias(void) {
	for (int i = 0; i < 4; i += 1) {
		delete materias[i];
		materias[i] = NULL;
	}
}
