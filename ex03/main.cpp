#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "test.hpp"

static bool	character_default_constructor(void);
static bool	character_name_constructor(void);
static bool	ice_default_constructor(void);
static bool	cure_default_constructor(void);
static bool	materiasource_default_constructor(void);
static bool	character_equip_unequip(void);
static bool	materiasource_learnMateria(void);
static bool	character_use(void);
static bool	character_copy_assignment(void);
static bool	character_copy_constructor(void);
static bool	materiasource_createMateria(void);
static bool	materiasource_copy_assignment(void);
static bool	materiasource_copy_constructor(void);
static bool	default_test(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		character_default_constructor,
		character_name_constructor,
		ice_default_constructor,
		cure_default_constructor,
		materiasource_default_constructor,
		character_equip_unequip,
		materiasource_learnMateria,
		character_use,
		character_copy_assignment,
		character_copy_constructor,
		materiasource_createMateria,
		materiasource_copy_assignment,
		materiasource_copy_constructor,
		default_test
	};
	size_t	tests_count = sizeof(tests) / sizeof(tests[0]);
	for (size_t i = 0; success && i < tests_count; i += 1) {
		success = tests[i]();
		std::cout << '\n';
	}
	if (success)
		std::cout << "OK\n";
	return success;
}

TEST_START(default_test)
	IMateriaSource	*src = NULL;
	ICharacter		*me = NULL;
	ICharacter		*bob = NULL;
	AMateria		*tmp = NULL;
	TEST_LOGIC_START
		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		me = new Character("me");

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = NULL;

		bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		expected = "* shoots an ice bolt at bob *\n"
			"* heals bob's wounds *\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete tmp;
	TEST_EMERGENCY_END
	delete bob;
	delete me;
	delete src;
TEST_END

TEST_START(materiasource_copy_constructor)
	AMateria	*tmp = NULL;
	TEST_LOGIC_START
		MateriaSource	src;
		const std::string	iceName = "ice";
		const std::string	cureName = "cure";
		tmp = src.createMateria(iceName);
		TEST_ASSERT(tmp == NULL)
		tmp = src.createMateria(cureName);
		TEST_ASSERT(tmp == NULL)
		src.learnMateria(new Ice());
		src.learnMateria(new Ice());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		MateriaSource	clone = src;
		tmp = clone.createMateria(cureName);
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == cureName)
		delete tmp;
		tmp = clone.createMateria(iceName);
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == iceName)
		delete tmp;
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete tmp;
	TEST_EMERGENCY_END
TEST_END

TEST_START(materiasource_copy_assignment)
	AMateria	*tmp = NULL;
	TEST_LOGIC_START
		const std::string	iceName = "ice";
		const std::string	cureName = "cure";
		MateriaSource	iceSrc;
		MateriaSource	cureSrc;

		iceSrc.learnMateria(new Ice());
		iceSrc.learnMateria(new Ice());
		iceSrc.learnMateria(new Ice());
		iceSrc.learnMateria(new Ice());
		cureSrc.learnMateria(new Cure());
		cureSrc.learnMateria(new Cure());
		cureSrc.learnMateria(new Cure());
		cureSrc.learnMateria(new Cure());
		tmp = cureSrc.createMateria(iceName);
		TEST_ASSERT(tmp == NULL)
		tmp = iceSrc.createMateria(cureName);
		TEST_ASSERT(tmp == NULL)
		tmp = iceSrc.createMateria(iceName);
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == iceName);
		delete tmp;
		tmp = cureSrc.createMateria("cure");
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == cureName)
		delete tmp;
		cureSrc = iceSrc;
		tmp = cureSrc.createMateria(cureName);
		TEST_ASSERT(tmp == NULL)
		tmp = cureSrc.createMateria(iceName);
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(tmp->getType() == iceName);
		delete tmp;
		tmp = NULL;
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete tmp;
	TEST_EMERGENCY_END
TEST_END

TEST_START(materiasource_createMateria)
	AMateria	*tmp = NULL;
	TEST_LOGIC_START
		const std::string	iceName = "ice";
		const std::string	cureName = "cure";
		MateriaSource	src;
		src.learnMateria(NULL);
		tmp = src.createMateria(iceName);
		TEST_ASSERT(tmp == NULL)
		tmp = src.createMateria(cureName);
		TEST_ASSERT(tmp == NULL)
		tmp = src.createMateria("any");
		TEST_ASSERT(tmp == NULL)
		AMateria	*ice = new Ice();
		TEST_ASSERT(!ice->isOwned())
		src.learnMateria(ice);
		tmp = src.createMateria(iceName);
		TEST_ASSERT(ice->isOwned())
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == iceName)
		delete tmp;
		tmp = NULL;
		tmp = src.createMateria("ice");
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == iceName)
		delete tmp;
		tmp = NULL;
		src.learnMateria(new Cure());
		tmp = src.createMateria("cure");
		TEST_ASSERT(tmp != NULL)
		TEST_ASSERT(!tmp->isOwned())
		TEST_ASSERT(tmp->getType() == cureName)
		delete tmp;
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		delete tmp;
	TEST_EMERGENCY_END
TEST_END

TEST_START(character_copy_constructor)
	TEST_LOGIC_START
		Character	matt("Matt");
		matt.equip(new Ice());
		matt.equip(new Cure());
		Character	clone = matt;
		TEST_ASSERT(clone.getName() == matt.getName())
		clone.use(0, matt);
		clone.use(1, matt);
		clone.use(2, matt);
		clone.use(3, matt);
		expected = "* shoots an ice bolt at Matt *\n"
				"* heals Matt's wounds *\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(character_copy_assignment)
	TEST_LOGIC_START
		Character	matt = Character("Matt");
		Character	copy = Character();
		TEST_ASSERT(matt.getName() == "Matt")
		TEST_ASSERT(copy.getName() == "Unnamed")
		matt.use(0, copy);
		matt.use(1, copy);
		matt.use(2, copy);
		matt.use(3, copy);
		copy.use(0, matt);
		copy.use(1, matt);
		copy.use(2, matt);
		copy.use(3, matt);
		copy.equip(new Ice());
		copy.equip(new Cure());
		matt.equip(new Cure());
		matt.equip(new Ice());
		matt.equip(new Cure());
		matt.equip(new Ice());
		copy = matt;
		TEST_ASSERT(copy.getName() == matt.getName())
		matt.use(3, copy);
		matt.use(2, copy);
		matt.use(1, copy);
		matt.use(0, copy);
		copy.use(3, matt);
		copy.use(2, matt);
		copy.use(1, matt);
		copy.use(0, matt);
		matt.use(3, copy);
		matt.use(2, copy);
		matt.use(1, copy);
		matt.use(0, copy);
		copy.use(3, matt);
		copy.use(2, matt);
		copy.use(1, matt);
		copy.use(0, matt);

		expected = "* shoots an ice bolt at Matt *\n"
			"* heals Matt's wounds *\n"
			"* shoots an ice bolt at Matt *\n"
			"* heals Matt's wounds *\n"
			"* shoots an ice bolt at Matt *\n"
			"* heals Matt's wounds *\n"
			"* shoots an ice bolt at Matt *\n"
			"* heals Matt's wounds *\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(character_use)
	Character	matt("Matt");
	Character	dummy;
	AMateria	*ice = NULL;
	AMateria	*cure = NULL;
	TEST_LOGIC_START
		ice = new Ice();
		cure = new Cure();
		matt.equip(ice);
		matt.equip(cure);
		matt.equip(new Ice());
		matt.equip(new Ice());
		TEST_ASSERT(ice->isOwned())
		TEST_ASSERT(cure->isOwned())
		matt.use(4, dummy);
		matt.use(-1, dummy);
		matt.use(0, dummy);
		matt.use(0, dummy);
		matt.use(1, dummy);
		matt.use(1, dummy);
		expected = "* shoots an ice bolt at Unnamed *\n"
			"* heals Unnamed's wounds *\n";
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
TEST_END

TEST_START(materiasource_learnMateria)
	IMateriaSource	*src1 = NULL;
	IMateriaSource	*src2 = NULL;
	AMateria	*cure1 = NULL;
	AMateria	*cure2 = NULL;
	AMateria	*ice1 = NULL;
	AMateria	*ice2 = NULL;
	AMateria	*ice3 = NULL;
	TEST_LOGIC_START
		src1 = new MateriaSource();
		src2 = new MateriaSource();
		cure1 = new Cure();
		cure2 = new Cure();
		ice1 = new Ice();
		ice2 = new Ice();
		ice3 = new Ice();
		TEST_ASSERT(!cure1->isOwned())
		TEST_ASSERT(!cure2->isOwned())
		TEST_ASSERT(!ice1->isOwned())
		TEST_ASSERT(!ice2->isOwned())
		TEST_ASSERT(!ice3->isOwned())
		src1->learnMateria(cure1);
		src1->learnMateria(cure1);
		src1->learnMateria(cure2);
		src1->learnMateria(cure2);
		src1->learnMateria(ice1);
		src1->learnMateria(ice1);
		src1->learnMateria(ice2);
		src1->learnMateria(ice2);
		src1->learnMateria(ice3);
		TEST_ASSERT(cure1->isOwned())
		TEST_ASSERT(cure2->isOwned())
		TEST_ASSERT(ice1->isOwned())
		TEST_ASSERT(ice2->isOwned())
		TEST_ASSERT(!ice3->isOwned())
		src2->learnMateria(cure1);
		src2->learnMateria(cure2);
		src2->learnMateria(ice1);
		src2->learnMateria(ice2);
		src2->learnMateria(ice3);
		TEST_ASSERT(cure1->isOwned())
		TEST_ASSERT(cure2->isOwned())
		TEST_ASSERT(ice1->isOwned())
		TEST_ASSERT(ice2->isOwned())
		TEST_ASSERT(ice3->isOwned())
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		if (src1) {
			static_cast<MateriaSource*>(src1)->freeSlot(0);
			static_cast<MateriaSource*>(src1)->freeSlot(1);
			static_cast<MateriaSource*>(src1)->freeSlot(2);
			static_cast<MateriaSource*>(src1)->freeSlot(3);
		}
		if (src2)
			static_cast<MateriaSource*>(src2)->freeSlot(0);
		delete cure1;
		delete cure2;
		delete ice1;
		delete ice2;
		delete ice3;
	TEST_EMERGENCY_END
	delete src1;
	delete src2;
TEST_END

TEST_START(character_equip_unequip)
	ICharacter	*matt = NULL;
	ICharacter	*sue = NULL;
	AMateria	*cure1 = NULL;
	AMateria	*cure2 = NULL;
	AMateria	*ice1 = NULL;
	AMateria	*ice2 = NULL;
	AMateria	*ice3 = NULL;
	TEST_LOGIC_START
		matt = new Character("Matt");
		sue = new Character("Sue");
		cure1 = new Cure();
		cure2 = new Cure();
		ice1 = new Ice();
		ice2 = new Ice();
		ice3 = new Ice();
		matt->equip(cure1);
		matt->equip(cure2);
		matt->equip(ice1);
		matt->equip(ice2);
		matt->equip(ice3);
		TEST_ASSERT(cure1->isOwned())
		TEST_ASSERT(cure2->isOwned())
		TEST_ASSERT(ice1->isOwned())
		TEST_ASSERT(ice2->isOwned())
		TEST_ASSERT(!ice3->isOwned())
		matt->equip(cure1);
		matt->equip(cure2);
		matt->equip(ice1);
		matt->equip(ice2);
		TEST_ASSERT(cure1->isOwned())
		TEST_ASSERT(cure2->isOwned())
		TEST_ASSERT(ice1->isOwned())
		TEST_ASSERT(ice2->isOwned())
		TEST_ASSERT(!ice3->isOwned())
		sue->equip(cure1);
		sue->equip(cure2);
		sue->equip(ice1);
		sue->equip(ice2);
		sue->equip(ice3);
		matt->unequip(-1);
		matt->unequip(4);
		matt->unequip(0);
		matt->unequip(2);
		matt->unequip(0);
		matt->unequip(2);
		TEST_ASSERT(!cure1->isOwned())
		TEST_ASSERT(cure2->isOwned())
		TEST_ASSERT(!ice1->isOwned())
		TEST_ASSERT(ice2->isOwned())
		TEST_ASSERT(ice3->isOwned())
		sue->equip(cure1);
		sue->equip(ice1);
		TEST_ASSERT(cure1->isOwned())
		TEST_ASSERT(cure2->isOwned())
		TEST_ASSERT(ice1->isOwned())
		TEST_ASSERT(ice2->isOwned())
		TEST_ASSERT(ice3->isOwned())
	TEST_LOGIC_END
	TEST_EMERGENCY_START
		if (matt) {
			matt->unequip(0);
			matt->unequip(1);
			matt->unequip(2);
			matt->unequip(3);
		}
		if (sue) {
			sue->unequip(0);
			sue->unequip(1);
			sue->unequip(2);
			sue->unequip(3);
		}
		delete cure1;
		delete cure2;
		delete ice1;
		delete ice2;
		delete ice3;
	TEST_EMERGENCY_END
	delete matt;
	delete sue;
TEST_END

TEST_START(materiasource_default_constructor)
	const IMateriaSource	*source = NULL;
	TEST_LOGIC_START
		source = new MateriaSource();
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
	delete source;
TEST_END

TEST_START(cure_default_constructor)
	const AMateria	*cure = NULL;
	TEST_LOGIC_START
		cure = new Cure();
		TEST_ASSERT(cure->getType() == "cure")
		TEST_ASSERT(cure->isOwned() == false)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
	delete cure;
TEST_END

TEST_START(ice_default_constructor)
	const AMateria	*ice = NULL;
	TEST_LOGIC_START
		ice = new Ice();
		TEST_ASSERT(ice->getType() == "ice")
		TEST_ASSERT(ice->isOwned() == false)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
	delete ice;
TEST_END

TEST_START(character_name_constructor)
	const ICharacter	*character = NULL;
	TEST_LOGIC_START
		const std::string	name = "Matt";
		character = new Character(name);
		TEST_ASSERT(character->getName() == name)
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
	delete character;
TEST_END

TEST_START(character_default_constructor)
	const ICharacter	*character = NULL;
	TEST_LOGIC_START
		character = new Character();
		TEST_ASSERT(character->getName() == "Unnamed")
	TEST_LOGIC_END
	TEST_EMERGENCY_START
	TEST_EMERGENCY_END
	delete character;
TEST_END
