#include "memoire2.h"


int lectureMemoire (int id) {
	return Memoire[id];
}

void ecritureMemoire (int id, int value) {
	Memoire[id] = value;
}

void initMemoire () {
	int i;
	
	for (i = 0 ; i < TAILLE_MEMOIRE ; i++) {
		Memoire[i] = 0;
	}
}

void afficherMemoire () {
	int i;
	
	for (i = 0 ; i < TAILLE_MEMOIRE ; i++) {
		printf("%d : %d\n", i*4, Memoire[i]);
	}
}