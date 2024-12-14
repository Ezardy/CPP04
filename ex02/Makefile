all: test

src=main AAnimal Cat Dog WrongAnimal WrongCat Brain
obj=$(addsuffix .o, $(src))

test: $(obj)
	c++ -o $@ $(obj)

iflags=-Wall -Wextra -Werror -std=c++98
command=c++ $(iflags) -o $@ -c $<

main.o: main.cpp AAnimal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp test.hpp Makefile
	$(command)

AAnimal.o: AAnimal.cpp AAnimal.hpp Makefile
	$(command)

WrongAnimal.o: WrongAnimal.cpp WrongAnimal.hpp Makefile
	$(command)

Cat.o: Cat.cpp Cat.hpp AAnimal.hpp Makefile
	$(command)

Dog.o: Dog.cpp Dog.hpp AAnimal.hpp Makefile
	$(command)

WrongCat.o: WrongCat.cpp WrongCat.hpp WrongAnimal.hpp Makefile
	$(command)

Brain.o: Brain.cpp Brain.hpp Makefile
	$(command)

clean:
	rm -f $(obj)

fclean: clean
	rm -f test

re: fclean test

debug: iflags+=-g
debug: test