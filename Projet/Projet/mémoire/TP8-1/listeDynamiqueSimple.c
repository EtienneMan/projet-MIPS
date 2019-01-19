/**
  * CS351 - Corrections de TP 2016-2017
  * Projet TP9-1
  * listeDynamiqueSimple.c
  * Eva Gerbert-Gaillard
  */
  
  
#include "listeDynamiqueSimple.h"


/*DEBUG DE MEMOIRE MALLOC/FREE (option dans listeDynamiqueSimple.h)*/
#ifdef DEBUG_MEM
	void no_op(enum mcheck_status status){}
#endif



element* elementLibre() {
	/*Allocation de mémoire*/
	element* e = (element*) malloc(sizeof(element));	

	/*DEBUG DE MEMOIRE MALLOC/FREE*/
	#ifdef DEBUG_MEM
		mcheck(&no_op);
	#endif
	

	/*Initialisation*/
	(*e).valeur = 0;
	(*e).suivant = NULL;
	return e;
}

void afficherListe(liste *l) {
	element *select;
	select = *l;

	while (select!=NULL) {
		printf("%4d", (*select).valeur);
		select = (*select).suivant;
	}
	printf("\n");
}

void insererElement(int x, liste *l) {
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
		
		
		/*DEBUG DE MEMOIRE MALLOC/FREE*/
		#ifdef DEBUG_MEM
			/*Verification du fonctionnement de free*/
			printf("Free de : %4d[%10p]\n", (*suiv).valeur, (void*) suiv);
			printf("Avant : %d (doit valoir %d)\n", mprobe(suiv), MCHECK_OK);
			free(suiv);
			printf("Après : %d (doit valoir %d)\n\n", mprobe(suiv), MCHECK_FREE);
		#else
			/*Liberation de la mémoire*/
			free(suiv);
		#endif
		
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

		/*DEBUG DE MEMOIRE MALLOC/FREE*/
		#ifdef DEBUG_MEM
			/*Verification du fonctionnement de free*/
			printf("Free de : %4d[%10p]\n", (*select).valeur, (void*) select);
			printf("Avant : %d (doit valoir %d)\n", mprobe(select), MCHECK_OK);
			free(select);
			printf("Après : %d (doit valoir %d)\n\n", mprobe(select), MCHECK_FREE);
		#else
			/*Liberation de la mémoire, élément par élement*/
			free(select);
		#endif
	}
	
	/*Permet de s'assurer que la liste pointe sur un élément nul si elle est utilisée ensuite*/
	(*l)=NULL;
}

