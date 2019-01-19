all: main.o hexa.o file.o
	gcc -o hexa main.o hexa.o file.o
	
main.o: main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o
	
hexa.o: hexa.c
	gcc -c hexa.c -Wall -ansi -pedantic -o hexa.o
	
file.o: file.c
	gcc -c file.c -Wall -ansi -pedantic -o file.o