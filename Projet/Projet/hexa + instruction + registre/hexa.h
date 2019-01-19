#ifndef __HEXA_H__
#define __HEXA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void instructionToHexa (char S[], char fichier[]);

void parseInstruction (char S[], char caracteres[], char p1[], char p2[], char p3[], int flagNegatif[]);

void instructionToBin (char S[]);
void remplirTableau (char S[], char bin[], int i, int j);

void decToBin (char S[], int nbrBits, int flagNegatif);
unsigned int binToDec (char S[]);

unsigned int puissance (unsigned int a, int b);

#endif