all: test

src=main Animal Cat Dog WrongAnimal WrongCat
obj=$(addsuffix .o, $(src))

test: $(obj)
	c++ -o $@ $(obj)

cflags=-Wall -Wextra -Werror -std=c++98
command=c++ $(cflags) -o $@ -c $<

main.o: main.cpp Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp test.hpp Makefile
	$(command)

Animal.o: Animal.cpp Animal.hpp Makefile
	$(command)

WrongAnimal.o: WrongAnimal.cpp WrongAnimal.hpp Makefile
	$(command)

Cat.o: Cat.cpp Cat.hpp Animal.hpp Makefile
	$(command)

Dog.o: Dog.cpp Dog.hpp Animal.hpp Makefile
	$(command)

WrongCat.o: WrongCat.cpp WrongCat.hpp WrongAnimal.hpp Makefile
	$(command)

clean:
	rm -f $(obj)

fclean: clean
	rm -f test

re: fclean test

debug: cflags+=-g
debug: test