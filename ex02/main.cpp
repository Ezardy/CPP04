#include "test.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

//static bool	animal_construction_destruction(void);
//static bool	animal_copy_constructor(void);
//static bool	animal_copy_assignment(void);
//static bool	animal_makeSound(void);
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
static bool	animal_array(void);
static bool	ex01_default(void);

int	main() {
	bool	success = true;
	bool	(*tests[])(void) = {
		//animal_construction_destruction,
		//animal_copy_constructor,
		//animal_copy_assignment,
		//animal_makeSound,
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
		ex00_default,
		animal_array,
		ex01_default
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

TEST_LOGIC_START(ex01_default)
	const AAnimal	*i = NULL;
	const AAnimal	*j = NULL;

	try {
		j = new Dog();
		i = new Cat();
	} catch (const std::bad_alloc &e) {
		success = false;
	}
	delete j;
	delete i;

	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Cat default constructor was called\n"
		"Brain destructor was called\n"
		"Dog destructor was called\n"
		"AAnimal destructor was called\n"
		"Brain destructor was called\n"
		"Cat destructor was called\n"
		"AAnimal destructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(animal_array)
	AAnimal	*array[10] = {};
	int i;

	try {
		for (i = 0; i < 10; i += 2) {
			array[i] = new Cat();
			array[i + 1] = new Dog();
			expected += "AAnimal constructor was called\n"
				"Brain default constructor was called\n"
				"Cat default constructor was called\n"
				"AAnimal constructor was called\n"
				"Brain default constructor was called\n"
				"Dog default constructor was called\n";
		}
		for (i = 0; i < 10; i += 2) {
			array[i]->makeSound();
			array[i + 1]->makeSound();
			expected += "MeowBark";
		}
	} catch (const std::bad_alloc &e) {
		success = false;
	}
	for (i = 0; i < 10; i += 2) {
		delete array[i];
		delete array[i + 1];
		expected += "Brain destructor was called\n"
			"Cat destructor was called\n"
			"AAnimal destructor was called\n"
			"Brain destructor was called\n"
			"Dog destructor was called\n"
			"AAnimal destructor was called\n";
	}
TEST_LOGIC_END

TEST_LOGIC_START(ex00_default)
	//const AAnimal	*meta = NULL;
	const AAnimal	*j = NULL;
	const AAnimal	*i = NULL;

	try {
		//meta = new AAnimal();
		j = new Dog();
		i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		//meta->makeSound();
	} catch (const std::bad_alloc &e) {
		success = false;
	}
	delete i;
	delete j;
	//delete meta;

	expected = //"AAnimal default constructor was called\n"
		"AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Cat default constructor was called\n"
		"Dog \n"
		"Cat \n"
		"MeowBarkBrain destructor was called\n"
		"Cat destructor was called\n"
		"AAnimal destructor was called\n"
		"Brain destructor was called\n"
		"Dog destructor was called\n"
		"AAnimal destructor was called\n";
		//"AAnimal destructor was called\n";
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
	try {
		const WrongCat	*cat = new WrongCat();

		if ((success = cat != NULL)) {
			success = cat->getType() == "WrongCat";
		}
		delete cat;
		expected = "WrongAnimal constructor was called\n"
			"WrongCat default constructor was called\n"
			"WrongCat destructor was called\n"
			"WrongAnimal destructor was called\n";
	} catch (const std::bad_alloc &e) {
		success = false;
	}
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
	static_cast<AAnimal&>(dog).makeSound();
	std::cout << '\n';
	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"BarkBark\n";
TEST_LOGIC_END

TEST_LOGIC_START(dog_makeSound)
	Dog	dog;

	std::cout << dog.getType() << ": ";
	dog.makeSound();
	std::cout << '\n';

	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"Dog: Bark\n";
TEST_LOGIC_END

TEST_LOGIC_START(dog_copy_assignment)
	Dog	dog;

	{
		Dog	puppy;

		puppy = dog;
		dog.barkThroughTranslator();
		success = puppy.getType() == "Dog"
			&& dog.barkThroughTranslator() != puppy.barkThroughTranslator();
	}
	try {
		dog.barkThroughTranslator();
		expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"Brain destructor was called\n"
		"Brain copy constructor was called\n"
		"Brain copy assignment was called\n"
		"Dog copy assignment was called\n"
		"Brain destructor was called\n"
		"Dog destructor was called\n"
		"AAnimal destructor was called\n";
	} catch(const std::exception &e) {
		success = false;
	}
TEST_LOGIC_END

TEST_LOGIC_START(dog_copy_costructor)
	Dog	dog;

	{
		Dog	puppy = dog;

		dog.barkThroughTranslator();
		success = puppy.getType() == "Dog"
			&& dog.barkThroughTranslator() != puppy.barkThroughTranslator();
	}

	try {
		dog.barkThroughTranslator();
		expected = "AAnimal constructor was called\n"
			"Brain default constructor was called\n"
			"Dog default constructor was called\n"
			"AAnimal constructor was called\n"
			"Brain copy constructor was called\n"
			"Brain copy assignment was called\n"
			"Dog copy constructor was called\n"
			"Brain destructor was called\n"
			"Dog destructor was called\n"
			"AAnimal destructor was called\n";
	} catch (const std::exception &e) {
		success = false;
	}
TEST_LOGIC_END

TEST_LOGIC_START(dog_construction_destruction) {
	Dog	dog;

	success = dog.getType() == "Dog";
	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Dog default constructor was called\n"
		"Brain destructor was called\n"
		"Dog destructor was called\n"
		"AAnimal destructor was called\n";
} TEST_LOGIC_END

TEST_LOGIC_START(cat_as_animal)
	Cat	cat;

	cat.makeSound();
	static_cast<AAnimal&>(cat).makeSound();
	std::cout << '\n';
	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Cat default constructor was called\n"
		"MeowMeow\n";
TEST_LOGIC_END

TEST_LOGIC_START(cat_makeSound)
	Cat	cat;

	std::cout << cat.getType() << ": ";
	cat.makeSound();
	std::cout << '\n';

	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Cat default constructor was called\n"
		"Cat: Meow\n";
TEST_LOGIC_END

TEST_LOGIC_START(cat_copy_assignment)
	Cat	cat;

	{
		Cat	kitten;

		kitten = cat;
		cat.meowThroughTranslator();
		success = kitten.getType() == "Cat"
			&& cat.meowThroughTranslator() != kitten.meowThroughTranslator();
	}

	try {
		cat.meowThroughTranslator();
		expected = "AAnimal constructor was called\n"
			"Brain default constructor was called\n"
			"Cat default constructor was called\n"
			"AAnimal constructor was called\n"
			"Brain default constructor was called\n"
			"Cat default constructor was called\n"
			"Brain destructor was called\n"
			"Brain copy constructor was called\n"
			"Brain copy assignment was called\n"
			"Cat copy assignment was called\n"
			"Brain destructor was called\n"
			"Cat destructor was called\n"
			"AAnimal destructor was called\n";
	} catch (const std::exception &e) {
		success = false;
	}
TEST_LOGIC_END

TEST_LOGIC_START(cat_copy_costructor)
	Cat	cat;

	{
		Cat	kitten = cat;
		
		cat.meowThroughTranslator();
		success = kitten.getType() == "Cat"
			&& cat.meowThroughTranslator() != kitten.meowThroughTranslator();
	}

	try {
		cat.meowThroughTranslator();
		expected = "AAnimal constructor was called\n"
			"Brain default constructor was called\n"
			"Cat default constructor was called\n"
			"AAnimal constructor was called\n"
			"Brain copy constructor was called\n"
			"Brain copy assignment was called\n"
			"Cat copy constructor was called\n"
			"Brain destructor was called\n"
			"Cat destructor was called\n"
			"AAnimal destructor was called\n";
	} catch (const std::exception &e) {
		success = false;
	}
TEST_LOGIC_END

TEST_LOGIC_START(cat_construction_destruction) {
	Cat	cat;

	success = cat.getType() == "Cat";
	expected = "AAnimal constructor was called\n"
		"Brain default constructor was called\n"
		"Cat default constructor was called\n"
		"Brain destructor was called\n"
		"Cat destructor was called\n"
		"AAnimal destructor was called\n";
} TEST_LOGIC_END

/*TEST_LOGIC_START(animal_makeSound)
	AAnimal	any;

	std::cout << any.getType() << '\n';
	any.makeSound();
	expected = "AAnimal default constructor was called\n\n";
TEST_LOGIC_END*/

/*TEST_LOGIC_START(animal_copy_assignment)
	AAnimal	any;
	AAnimal	tumbo;

	tumbo = any;

	success = tumbo.getType() == "";
	expected = "AAnimal default constructor was called\n"
		"AAnimal default constructor was called\n"
		"AAnimal copy assignment was called\n";
TEST_LOGIC_END*/

/*TEST_LOGIC_START(animal_copy_constructor)
	AAnimal	any;
	AAnimal	tumbo = any;

	success = tumbo.getType() == "";
	expected = "AAnimal default constructor was called\n"
		"AAnimal copy constructor was called\n";
TEST_LOGIC_END

TEST_LOGIC_START(animal_construction_destruction) {
	AAnimal	any;
	success = any.getType() == "";
	expected = "AAnimal default constructor was called\n"
		"AAnimal destructor was called\n";
} TEST_LOGIC_END*/
