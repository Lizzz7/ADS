all: main

main: main.o matrix.o
	gcc main.o matrix.o -o main

main.o: main.c matrix.h
	gcc -std=c99 -Wall -Werror -Wvla -c main.c

matrix.o: matrix.c matrix.h
	gcc -std=c99 -Wall -Werror -Wvla -c matrix.c

clean:
	rm -f *.o main

