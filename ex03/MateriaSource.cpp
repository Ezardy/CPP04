#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : materias() {

}

MateriaSource::MateriaSource(const MateriaSource &other) : materias() {
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

MateriaSource::~MateriaSource(void) {
	purgeMaterias();
}

void	MateriaSource::learnMateria(AMateria *materia) {
	if (materia && !materia->isOwned()) {
		for (int i = 0; i < 4; i += 1) {
			if (!materias[i]) {
				materias[i] = materia;
				materia->setOwned();
				i = 4;
			}
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string &type) {
	int			i;
	AMateria	*materia;

	for (i = 0; i < 4 && (!materias[i] || type != materias[i]->getType()); i += 1);
	if (i == 4)
		materia = NULL;
	else
		materia = materias[i]->clone();
	return materia;
}

void	MateriaSource::freeSlot(unsigned int idx) {
	if (idx < 4 && materias[idx]) {
		materias[idx]->unsetOwned();
		materias[idx] = NULL;
	}
}

void	MateriaSource::purgeMaterias(void) {
	for (int i = 0; i < 4; i += 1) {
		delete materias[i];
		materias[i] = NULL;
	}
}
