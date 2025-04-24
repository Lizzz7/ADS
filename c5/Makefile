all: main

main: main.o set.o
	gcc main.o set.o -o main

main.o: main.c set.h
	gcc -std=c99 -Wall -Werror -Wvla -c main.c

set.o: set.c set.h
	gcc -std=c99 -Wall -Werror -Wvla -c set.c

clean:
	rm -f *.o main

