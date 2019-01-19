#include "memoire.h"


element* elementLibre() {
	/*Allocation de mémoire*/
	element* e = (element*) malloc(sizeof(element));		

	/*Initialisation*/
	(*e).valeur = 0;
	(*e).suivant = NULL;
	return e;
}

void afficherMemoire(liste *memoire) {
	element *select;
	select = *l;

	while (select!=NULL) {
		printf("%4d", (*select).valeur);
		select = (*select).suivant;
	}
	printf("\n");
}

void insererElement(int x, liste *memoire) {
	element *select, *suiv, *libre;

	select = NULL;
	suiv = *l;
	
	/*Détermination de la position de l'insertion*/
	while ( (suiv != NULL) && ((*suiv).valeur < x) ){
		select = suiv;
		suiv = (*select).suivant;
	}
	
	/*Insertion*/
	libre = elementLibre();
	if (select == NULL) {
		(*l) = libre;
	}else{
		(*select).suivant = libre;
	}
	(*libre).valeur = x;
	(*libre).suivant = suiv;
	
	printf("Insertion de %d OK\n", x);
}

void supprimerElement(int i, liste *l) {
	element *select, *suiv;
	int n;
	
	n = i;
	select = NULL;
	suiv = *l;

	/*Détermination de la position de la suppression (attention aux indices))*/
	while ((suiv != NULL) && (i > 1)){
		select = suiv;
		suiv = (*select).suivant;
		i--;
	}
	if ((i <= 1) && (suiv == NULL)) {
		printf("Il n'y avait pas de %d-ème élément dans la liste\n", n);
	} else {
		/*Suppression de l'élément*/
		if (select == NULL) {
			(*l) = (*suiv).suivant;
		}else{
			(*select).suivant = (*suiv).suivant;
		}
		
		/*Liberation de la mémoire*/
		free(suiv);
				
		printf("Suppression du %d-ème élément OK\n", n);
	}
}


void libereMemoire(liste *l){
	element *select, *suiv;

	select = NULL;
	suiv = *l;
	
	while (suiv != NULL){
		select = suiv;
		suiv = (*select).suivant;

		/*Liberation de la mémoire, élément par élement*/
		free(select);
	}
	
	/*Permet de s'assurer que la liste pointe sur un élément nul si elle est utilisée ensuite*/
	(*l)=NULL;
}
