#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "test.hpp"

static bool	character_default_constructor(void);
static bool	character_name_constructor(void);
static bool	character_equip_unequip(void);
static bool	character_use(void);
static bool	character_copy_constructor(void);
static bool	character_copy_assignment(void);
static bool	materiasource_default_constructor(void);
static bool	materiasource_learnMateria(void);
static bool	materiasource_createMateria(void);
static bool	materiasource_copy_constructor(void);
static bool	materiasource_copy_assignment(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		character_default_constructor
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

TEST_LOGIC_START(reuse_materia)
	Character	matt("Matt");
TEST_LOGIC_END
