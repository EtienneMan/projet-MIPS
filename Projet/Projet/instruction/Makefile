all: main.o instruction.o hexa.o
	gcc -o hexa main.o instruction.o hexa.o
	
main.o: main.c
	gcc -c main.c -Wall -ansi -pedantic -o main.o
	
instruction.o: instruction.c
	gcc -c instruction.c -Wall -ansi -pedantic -o instruction.o
	
hexa.o: hexa.c
	gcc -c hexa.c -Wall -ansi -pedantic -o hexa.o