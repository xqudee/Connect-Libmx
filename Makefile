all: copy MINILIBMX little_clean

copy:
	mkdir obj
	cp inc/*.h obj/
	cp src/*.c obj/

MINILIBMX: 
	clang -c -std=c11 -Wall -Wextra -Werror -Wpedantic obj/*.c
	ar -rc libmx.a *.o

little_clean:
	rm -rf obj
	rm *.o

uninstall:
	rm libmx.a

clean:
	rm -rf src
	rm -rf inc
	rm -rf obj

reinstall:
	make uninstall
	make

