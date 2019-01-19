#include "instruction.h"


int convertChartoInt(char tab[], int flag) {
	int r = atoi(tab);
	
	if (flag == 1) {
		r *= -1;
	}
	
	return r;
}

void creerInstruction (Instruction *I, char S[]) {
	char caracteres[MAX], p1[MAX], p2[MAX], p3[MAX];
	int flag[MAX];
	
	parseInstruction(S, caracteres, p1, p2, p3, flag);
	
	strcpy(I->nom, caracteres);
	I->p1 = convertChartoInt(p1, fp1);
	I->p2 = convertChartoInt(p2, fp2);
	I->p3 = convertChartoInt(p3, fp3);
}

void ADDI (Instruction instruction) {
	ecritureRegistre(instruction.p2, lectureRegistre(instruction.p1) + instruction.p3);
}