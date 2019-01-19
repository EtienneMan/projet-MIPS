#ifndef __MEMOIRE_H__
#define __MEMOIRE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element element;
struct element {
	int valeur ;		/*valeur de l'element*/
	struct element* suivant ; /*adresse du successeur*/
};

/* le type liste est un pointeur vers le 1er élément d'une chaine*/
typedef element* liste;

void afficherMemoire(liste *memoire);

void insererElement(int x, liste *memoire);

void supprimerElement(int i, liste *l);

void libereMemoire(liste *l);

#endif
