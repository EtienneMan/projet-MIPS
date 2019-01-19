#include "file.h"


void createFile (char adresse[]) {
	FILE* fichier = NULL;
	fichier = fopen(adresse, "w");
	fclose(fichier);
}


int readFile (char adresse[], char instructions[][MAX]) {
	int j = 0;
	
	FILE* fichier = NULL;
	fichier = fopen(adresse, "r");
	
	/* On lit le fichier ligne par ligne */
	while (fgets (instructions[j], MAX, fichier) != NULL) {
		/* Si la ligne lue est vide ("\n"), on n'incr�mente pas j car elle ne nous int�resse pas */
		if (strcmp(instructions[j], "\n") != 0) {
			j ++;
		}
	}
	
	fclose(fichier);
	
	return j;
}