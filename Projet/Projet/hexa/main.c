#include "hexa.h"
#include "file.h"


int main (int argc, char *argv[]) {
	int i, tailleInstruction;
	char instructions[MAX][MAX];

	tailleInstruction = readFile (argv[1], instructions);

	createFile(argv[2]);

	for (i = 0 ; i < tailleInstruction ; i++) {
		instructionToHexa(instructions[i], argv[2]);
	}

	return 0;
}
