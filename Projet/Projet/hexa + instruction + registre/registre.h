#ifndef __REGISTRE_H__
#define __REGISTRE_H__

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_REGISTRE 32

/* Cr�ation des diff�rents registres */
int Registres[TAILLE_REGISTRE];
int PC, HI, LO;

int lectureRegistre (int id);
void ecritureRegistre (int id, int value);
void initRegistre ();
void afficherRegistre ();

#endif
