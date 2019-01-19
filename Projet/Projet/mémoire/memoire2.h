#ifndef __MEMOIRE_H__
#define __MEMOIRE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MEMOIRE 100

int Memoire[TAILLE_MEMOIRE];

int lectureMemoire (int id);
void ecritureMemoire (int id, int value);
void initMemoire ();
void afficherMemoire ();

#endif