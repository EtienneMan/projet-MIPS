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
void ADDI (Instruction instruction);

//Modification Etienne

void ADDI (Instruction instruction);
void ADD (Instruction instruction);
void OR (Instruction instruction);
void AND (Instruction instruction);
void LW (Instruction instruction);
void SW (Instruction instruction);
void MFLO (Instruction instruction);
void MFHI (Instruction instruction);
void MULT (Instruction instruction);
void SUB (Instruction instruction);
void DIV (Instruction instruction);
void SLL (Instruction instruction);
void SRL (Instruction instruction);
void SLT (Instruction instruction);
void XOR (Instruction instruction);
void BEQ (Instruction instruction);
void BGTZ (Instruction instruction);
void BLEZ (Instruction instruction);
void BNE (Instruction instruction);


#endif
