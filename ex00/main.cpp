#include "test.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

static bool	animal_construction_destruction(void);
static bool	animal_copy_constructor(void);
static bool	animal_copy_assignment(void);
static bool	animal_makeSound(void);
static bool	cat_construction_destruction(void);
static bool	cat_copy_costructor(void);
static bool	cat_copy_assignment(void);
static bool	cat_makeSound(void);
static bool	cat_as_animal(void);
static bool	dog_construction_destruction(void);
static bool	dog_copy_costructor(void);
static bool	dog_copy_assignment(void);
static bool	dog_makeSound(void);
static bool	dog_as_animal(void);
static bool	wronganimal_construction_destruction(void);
static bool	wronganimal_copy_constructor(void);
static bool	wronganimal_copy_assignment(void);
static bool	wronganimal_makeSound(void);
static bool	wrongcat_construction_destruction(void);
static bool	wrongcat_copy_costructor(void);
static bool	wrongcat_copy_assignment(void);
static bool	wrongcat_makeSound(void);
static bool	wrongcat_as_wronganimal(void);
static bool	ex00_default(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		animal_construction_destruction,
		animal_copy_constructor,
		animal_copy_assignment,
		animal_makeSound,
		cat_construction_destruction,
		cat_copy_costructor,
		cat_copy_assignment,
		cat_makeSound,
		cat_as_animal,
		dog_construction_destruction,
		dog_copy_costructor,
		dog_copy_assignment,
		dog_makeSound,
		dog_as_animal,
		wronganimal_construction_destruction,
		wronganimal_copy_constructor,
		wronganimal_copy_assignment,
		wronganimal_makeSound,
		wrongcat_construction_destruction,
		wrongcat_copy_costructor,
		wrongcat_copy_assignment,
		wrongcat_makeSound,
		wrongcat_as_wronganimal,
		ex00_default
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

TEST_LOGIC_START(ex00_default)
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	if ((success = meta && i && j)) {
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
	}
	delete i;
	delete j;
	delete meta;

	expected = "Animal default constructor was called\n"
		"Animal constructor was called\n"
		"Dog default constructor was called\n"
		"Animal constructor was called\n"
		"Cat default constructor was called\n"
		"Dog \n"
		"Cat \n"
		"MeowBarkCat destructor was called\n"
		"Animal destructor was called\n"
		"Dog destructor was called\n"
		"Animal destructor was called\n"
		"Animal destructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(wrongcat_as_wronganimal)
	WrongCat	cat;

	cat.makeSound();
	static_cast<WrongAnimal&>(cat).makeSound();
	std::cout << '\n';
	expected = "WrongAnimal constructor was called\n"
		"WrongCat default constructor was called\n"
		"Meow\n";
TEST_LOGIC_END

TEST_LOGIC_START(wrongcat_makeSound)
	WrongCat	cat;

	std::cout << cat.getType() << ": ";
	cat.makeSound();
	std::cout << '\n';

	expected = "WrongAnimal constructor was called\n"
		"WrongCat default constructor was called\n"
		"WrongCat: Meow\n";
TEST_LOGIC_END

TEST_LOGIC_START(wrongcat_copy_assignment)
	WrongCat	cat;
	WrongCat	kitten;

	kitten = cat;

	success = kitten.getType() == "WrongCat";
	expected = "WrongAnimal constructor was called\n"
		"WrongCat default constructor was called\n"
		"WrongAnimal constructor was called\n"
		"WrongCat default constructor was called\n"
		"WrongCat copy assignment was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(wrongcat_copy_costructor)
	WrongCat	cat;
	WrongCat	kitten = cat;

	success = kitten.getType() == "WrongCat";
	expected = "WrongAnimal constructor was called\n"
		"WrongCat default constructor was called\n"
		"WrongAnimal constructor was called\n"
		"WrongCat copy constructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(wrongcat_construction_destruction)
	const WrongCat	*cat = new WrongCat();

	if ((success = cat != NULL)) {
		success = cat->getType() == "WrongCat";
	}
	delete cat;
	expected = "WrongAnimal constructor was called\n"
		"WrongCat default constructor was called\n"
		"WrongCat destructor was called\n"
		"WrongAnimal destructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(wronganimal_makeSound)
	WrongAnimal	any;

	std::cout << any.getType() << '\n';
	any.makeSound();
	expected = "WrongAnimal default constructor was called\n\n";
TEST_LOGIC_END

TEST_LOGIC_START(wronganimal_copy_assignment)
	WrongAnimal	any;
	WrongAnimal	tumbo;

	tumbo = any;

	success = tumbo.getType() == "";
	expected = "WrongAnimal default constructor was called\n"
		"WrongAnimal default constructor was called\n"
		"WrongAnimal copy assignment was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(wronganimal_copy_constructor)
	WrongAnimal	any;
	WrongAnimal	tumbo = any;

	success = tumbo.getType() == "";
	expected = "WrongAnimal default constructor was called\n"
		"WrongAnimal copy constructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(wronganimal_construction_destruction) {
	WrongAnimal	any;
	success = any.getType() == "";
	expected = "WrongAnimal default constructor was called\n"
		"WrongAnimal destructor was called\n";
} TEST_LOGIC_END

TEST_LOGIC_START(dog_as_animal)
	Dog	dog;

	dog.makeSound();
	static_cast<Animal&>(dog).makeSound();
	std::cout << '\n';
	expected = "Animal constructor was called\n"
		"Dog default constructor was called\n"
		"BarkBark\n";
TEST_LOGIC_END

TEST_LOGIC_START(dog_makeSound)
	Dog	dog;

	std::cout << dog.getType() << ": ";
	dog.makeSound();
	std::cout << '\n';

	expected = "Animal constructor was called\n"
		"Dog default constructor was called\n"
		"Dog: Bark\n";
TEST_LOGIC_END

TEST_LOGIC_START(dog_copy_assignment)
	Dog	dog;
	Dog	puppy;

	puppy = dog;

	success = puppy.getType() == "Dog";
	expected = "Animal constructor was called\n"
		"Dog default constructor was called\n"
		"Animal constructor was called\n"
		"Dog default constructor was called\n"
		"Dog copy assignment was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(dog_copy_costructor)
	Dog	dog;
	Dog	puppy = dog;

	success = puppy.getType() == "Dog";
	expected = "Animal constructor was called\n"
		"Dog default constructor was called\n"
		"Animal constructor was called\n"
		"Dog copy constructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(dog_construction_destruction) {
	Dog	dog;

	success = dog.getType() == "Dog";
	expected = "Animal constructor was called\n"
		"Dog default constructor was called\n"
		"Dog destructor was called\n"
		"Animal destructor was called\n";
} TEST_LOGIC_END

TEST_LOGIC_START(cat_as_animal)
	Cat	cat;

	cat.makeSound();
	static_cast<Animal&>(cat).makeSound();
	std::cout << '\n';
	expected = "Animal constructor was called\n"
		"Cat default constructor was called\n"
		"MeowMeow\n";
TEST_LOGIC_END

TEST_LOGIC_START(cat_makeSound)
	Cat	cat;

	std::cout << cat.getType() << ": ";
	cat.makeSound();
	std::cout << '\n';

	expected = "Animal constructor was called\n"
		"Cat default constructor was called\n"
		"Cat: Meow\n";
TEST_LOGIC_END

TEST_LOGIC_START(cat_copy_assignment)
	Cat	cat;
	Cat	kitten;

	kitten = cat;

	success = kitten.getType() == "Cat";
	expected = "Animal constructor was called\n"
		"Cat default constructor was called\n"
		"Animal constructor was called\n"
		"Cat default constructor was called\n"
		"Cat copy assignment was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(cat_copy_costructor)
	Cat	cat;
	Cat	kitten = cat;

	success = kitten.getType() == "Cat";
	expected = "Animal constructor was called\n"
		"Cat default constructor was called\n"
		"Animal constructor was called\n"
		"Cat copy constructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(cat_construction_destruction) {
	Cat	cat;

	success = cat.getType() == "Cat";
	expected = "Animal constructor was called\n"
		"Cat default constructor was called\n"
		"Cat destructor was called\n"
		"Animal destructor was called\n";
} TEST_LOGIC_END

TEST_LOGIC_START(animal_makeSound)
	Animal	any;

	std::cout << any.getType() << '\n';
	any.makeSound();
	expected = "Animal default constructor was called\n\n";
TEST_LOGIC_END

TEST_LOGIC_START(animal_copy_assignment)
	Animal	any;
	Animal	tumbo;

	tumbo = any;

	success = tumbo.getType() == "";
	expected = "Animal default constructor was called\n"
		"Animal default constructor was called\n"
		"Animal copy assignment was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(animal_copy_constructor)
	Animal	any;
	Animal	tumbo = any;

	success = tumbo.getType() == "";
	expected = "Animal default constructor was called\n"
		"Animal copy constructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(animal_construction_destruction) {
	Animal	any;
	success = any.getType() == "";
	expected = "Animal default constructor was called\n"
		"Animal destructor was called\n";
} TEST_LOGIC_END
