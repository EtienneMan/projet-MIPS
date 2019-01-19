#include "registre.h"


int lectureRegistre (int id) {
	return Registres[id];
}

void ecritureRegistre (int id, int value) {
	Registres[id] = value;
}

void initRegistre () {
	int i;
	
	for (i = 0 ; i < TAILLE_REGISTRE ; i++) {
		Registres[i] = 0;
	}
	
	PC = HI = LO = 0;
}

void afficherRegistre () {
	int i;
	
	for (i = 0 ; i < TAILLE_REGISTRE ; i++) {
		printf("Registre $%d : %d\n", i, Registres[i]);
	}
}
