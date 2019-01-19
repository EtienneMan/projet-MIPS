/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP9-1
  * listeDynamiqueSimple.h
  * Eva Gerbert-Gaillard
  */

#ifndef __LISTEDYNAMIQUESIMPLE_H__
#define __LISTEDYNAMIQUESIMPLE_H__

#include <stdio.h>
#include <stdlib.h>

/*DEBUG DE MEMOIRE MALLOC/FREE - Décommenter le define pour activer (non obligatoire)*/
/*#define DEBUG_MEM*/

#ifdef DEBUG_MEM
#include <mcheck.h>
#endif


typedef struct element element;
struct element {
	int valeur ;		/*valeur de l'element*/
	struct element* suivant ; /*adresse du successeur*/
};

/* le type liste est un pointeur vers le 1er élément d'une chaine*/
typedef element* liste;


void afficherListe(liste *l);

void insererElement(int x, liste *l);

void supprimerElement(int i, liste *l);

void libereMemoire(liste *l);


#endif
