#include "instruction.h"

#define MAX 100

int main () {
	char S[] = "ADDI $8,$0,1";
	Instruction instruction;
	
	creerInstruction(&instruction, S);
	
	printf("%s\n", instruction.nom);
	printf("%d\n", instruction.p1);
	printf("%d\n", instruction.p2);
	printf("%d\n", instruction.p3);
	
	return 0;
}