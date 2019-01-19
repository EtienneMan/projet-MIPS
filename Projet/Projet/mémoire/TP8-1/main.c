/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP9-1
  * main.c
  * Eva Gerbert-Gaillard
  */

#include <stdio.h>
#include <stdlib.h>

#include "listeDynamiqueSimple.h"


int main()
{
	int x;
	int choix = 1;

	liste l = NULL;	
	
	/*DEBUG DE MEMOIRE MALLOC/FREE(option dans listeDynamiqueSimple.h)*/
	#ifdef DEBUG_MEM
		mcheck(NULL); /*A effectuer au moins une fois avant le premier malloc*/
	#endif

	printf("Bienvenue dans le programme de liste chainee.\n");
	/* test switch pour pouvoir facilement tout tester */
	do {
		printf("Pour quitter : Entrez 0\n\
	Pour afficher la liste : Entrez 1\n\
	Pour inserer un element dans la liste : Entrez 2 \n\
	Pour supprimer un element dans la liste : Entrez 3 \n\
	Choix : ");
		scanf("%d", &choix);
		printf("\n");
		switch (choix) {
			case 1 : afficherListe(&l);
				break;
			case 2 : 
				printf("Entrez l'element a inserer : ");
				scanf("%d", &x);
				insererElement(x, &l);
				break;
			case 3 : 
				printf("Entrez l'indice de l'element a supprimer : ");
				scanf("%d", &x);
				supprimerElement(x, &l);
				break;
			default : break;
		}
		printf("\n");
	}
	while (choix !=0);

	libereMemoire(&l); /* TRES important => libere la memoire allouee */

	return 0;
}
