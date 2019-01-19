#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hexa.h"
#include "registre.h"

#define  fp1 flag[0]
#define  fp2 flag[1]
#define fp3 flag[2] 
#define MAX 100


typedef struct Instruction Instruction;
struct Instruction {
	char nom[MAX];
	int p1, p2, p3;
};


int convertChartoInt(char tab[], int flag);
void creerInstruction (Instruction *I, char S[]);


#endif