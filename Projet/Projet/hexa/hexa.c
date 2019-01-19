#include "hexa.h"


void instructionToHexa (char S[], char adresse[]) {
	char caracteres[MAX], p1[MAX], p2[MAX], p3[MAX];
	int flagNegatif[3] = {0, 0, 0};
	FILE* fichier = NULL;

	parseInstruction(S, caracteres, p1, p2, p3, flagNegatif);
	instructionToBin(caracteres);


	/* On concanne caracteres, p1, p2, et p3 dans le bon sens */
	if (caracteres[0] == '1') {

		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);
		decToBin(p3, 5, flagNegatif[2]);

		remplirTableau(S, "000000", 0, 6);
		remplirTableau(S, p2, 6, 11);
		remplirTableau(S, p3, 11, 16);
		remplirTableau(S, p1, 16, 21);
		remplirTableau(S, "00000", 21, 26);
		remplirTableau(S, &caracteres[1], 26, 32);

	} else if (caracteres[0] == '0') {
		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);
		decToBin(p3, 16, flagNegatif[2]);

		remplirTableau(S, &caracteres[1], 0, 6);
		remplirTableau(S, p2, 6, 11);
		remplirTableau(S, p1, 11, 16);
		remplirTableau(S, p3, 16, 32);
	} else if (caracteres[0] == '2') { /*BGTZ et BLEZ*/
		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 16, flagNegatif[1]);

		remplirTableau(S, &caracteres[1], 0, 6);
		remplirTableau(S, p1, 6, 11);
		remplirTableau(S, "00000", 11, 16);
		remplirTableau(S, p2, 16, 32);
	} else if (caracteres[0] == '3') { /*DIV et MULT*/
		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);

		remplirTableau(S, "000000", 0, 6);
		remplirTableau(S, p1, 6, 11);
		remplirTableau(S, p2, 11, 16);
		remplirTableau(S, "00000000", 16, 26);
		remplirTableau(S, &caracteres[1], 26, 32);

	} else if (caracteres[0] == '4') { /*J et JAL*/
		decToBin(p1, 26, flagNegatif[0]);

		remplirTableau(S, &caracteres[1], 0, 6);
		remplirTableau(S, p1, 6, 32);

	} else if (caracteres[0] == '5') { /* JR*/
		decToBin(p1, 5, flagNegatif[0]);

		remplirTableau(S, "000000", 0, 6);
		remplirTableau(S, p1, 6, 11);
		remplirTableau(S, "0000000000", 11, 21);
		remplirTableau(S, "00000", 21, 26);
		remplirTableau(S, &caracteres[1], 26, 32);

	} else if (caracteres[0] == '6') { /*LUI*/
		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 16, flagNegatif[1]);

		remplirTableau(S, &caracteres[1], 0, 6);
		remplirTableau(S, "000000", 6, 11);
		remplirTableau(S, p1, 11, 16);
		remplirTableau(S, p2, 16, 32);

	} else if (caracteres[0] == '7') { /*MFHI MFLO*/

		decToBin(p1, 5, flagNegatif[0]);

		remplirTableau(S, "0000000000000000", 0, 16);
		remplirTableau(S, p1, 16, 21);
		remplirTableau(S, "00000", 21, 26);
		remplirTableau(S, &caracteres[1], 26, 32);
	} else if (caracteres[0] == '8') { /*NOP*/

		remplirTableau(S, "00000000000000000000000000", 0, 26);
		remplirTableau(S, &caracteres[1], 26, 32);
	} else if (caracteres[0] == '9') { /*SLL*/

		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);
		decToBin(p3, 5, flagNegatif[2]);

		remplirTableau(S, "00000000000", 0, 11);
		remplirTableau(S, p2, 11, 16);
		remplirTableau(S, p1, 16, 21);
		remplirTableau(S, p3, 21, 26);
		remplirTableau(S, &caracteres[1], 26, 32);
	} else if (caracteres[0] == 'A') { /*ROTR*/

		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);
		decToBin(p3, 5, flagNegatif[2]);
		remplirTableau(S, "00000000001", 0, 11);
		remplirTableau(S, p2, 11, 16);
		remplirTableau(S, p1, 16, 21);
		remplirTableau(S, p3, 21, 26);
		remplirTableau(S, &caracteres[1], 26, 32);
	} else if (caracteres[0] == 'B') { /*SRL*/

		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);
		decToBin(p3, 5, flagNegatif[2]);
		remplirTableau(S, "00000000000", 0, 11);
		remplirTableau(S, p2, 11, 16);
		remplirTableau(S, p1, 16, 21);
		remplirTableau(S, p3, 21, 26);
		remplirTableau(S, &caracteres[1], 26, 32);
	} else if (caracteres[0] == 'C') { /*SYSCALL A TERMINER*/

		remplirTableau(S, "000000", 0, 6);

	} else if (caracteres[0] == 'D') { /* BNE BEQ*/
		
		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 5, flagNegatif[1]);
		decToBin(p3, 16, flagNegatif[2]);

		remplirTableau(S, &caracteres[1], 0, 6);
		remplirTableau(S, p1, 6, 11);
		remplirTableau(S, p2, 11, 16);
		remplirTableau(S, p3, 16, 32);
	} else if (caracteres[0] == 'E') { /* LW */
		
		decToBin(p1, 5, flagNegatif[0]);
		decToBin(p2, 16, flagNegatif[1]);
		decToBin(p3, 5, flagNegatif[2]);

		remplirTableau(S, &caracteres[1], 0, 6);
		remplirTableau(S, p3, 6, 11);
		remplirTableau(S, p1, 11, 16);
		remplirTableau(S, p2, 16, 32);
	}


	fichier = fopen(adresse, "a");
	
	/* On écrit le code hexadécimal dans le fichier */
	fprintf(fichier, "%08X\n", binToDec(S));

	fclose(fichier);
}


void parseInstruction (char S[], char caracteres[], char p1[], char p2[], char p3[], int flagNegatif[]) {
	int i,j;
	
	/* Récupération de l'opcode */
	for (i = 0 ; S[i] != ' ' && S[i] != '\0' ; i++) {
		caracteres[i] = S[i];
	}
	caracteres[i] = '\0';
	
	/* Récupération de la première opérande (si elle existe) */
	for (j = 0 ; S[i] != ','  && S[i-1] != '\0' ; i++) {
		if (S[i] == '-') {
			flagNegatif[0] = 1;
		}
		if (S[i] >= '0' && S[i] <= '9') {
			p1[j] = S[i];
			j++;
		}
	}
	p1[j] = '\0';
	i++;
	
	/* Récupération de la deuxième opérande (si elle existe) */
	for (j = 0 ; S[i] != ',' && S[i] != '('  && S[i-2] != '\0' ; i++) {
		if (S[i] == '-') {
			flagNegatif[1] = 1;
		}
		if (S[i] >= '0' && S[i] <= '9') {
			p2[j] = S[i];
			j++;
		}
	}
	p2[j] = '\0';
	i++;
	
	/* Récupération de la troisième opérande (si elle existe) */
	for (j = 0 ; S[i] != '\0' && S[i-3] != '\0' ; i++) {
		if (S[i] == '-') {
			flagNegatif[2] = 1;
		}
		if (S[i] >= '0' && S[i] <= '9') {
			p3[j] = S[i];
			j++;
		}
	}
	p3[j] = '\0';
	}


void instructionToBin (char S[]) {
	/*
	Le premier bit correspond au bit d'indication.
	Il indique comment concaténer l'instruction avant la conversion en hexadécimal.

	Les 6 derniers bits correspondent ï¿½ l'opcode.
	*/

	if (strcmp(S, "ADDI") == 0) {
			remplirTableau(S, "0001000", 0, 7);
	} else if (strcmp(S, "ADD") == 0) {
			remplirTableau(S, "1100000", 0, 7);
	}  else if (strcmp(S, "BEQ") == 0) {
			remplirTableau(S, "D000100", 0, 7);
	} else if (strcmp(S, "AND") == 0) {
			remplirTableau(S, "1100100", 0, 7);
	} else if (strcmp(S, "BLEZ") == 0) {
			remplirTableau(S, "2000110", 0, 7);
	} else if (strcmp(S, "BGTZ") == 0) {
			remplirTableau(S, "2000111", 0, 7);
	} else if (strcmp(S, "DIV") == 0) {
			remplirTableau(S, "3011010", 0, 7);
	} else if (strcmp(S, "BNE") == 0) {
			remplirTableau(S, "D000101", 0, 7);
	} else if (strcmp(S, "J") == 0) {
			remplirTableau(S, "4000010", 0, 7);
	} else if (strcmp(S, "JR") == 0) {
			remplirTableau(S, "5001000", 0, 7);
	} else if (strcmp(S, "JAL") == 0) {
			remplirTableau(S, "4000011", 0, 7);
	} else if (strcmp(S, "LUI") == 0) {
			remplirTableau(S, "6001111", 0, 7);
	} else if (strcmp(S, "MFHI") == 0) {
			remplirTableau(S, "7010000", 0, 7);
	} else if (strcmp(S, "LW") == 0) {
			remplirTableau(S, "E100011", 0, 7);
	} else if (strcmp(S, "MULT") == 0) {
			remplirTableau(S, "3011000", 0, 7);
	} else if (strcmp(S, "MFLO") == 0) {
			remplirTableau(S, "7010010", 0, 7);
	} else if (strcmp(S, "OR") == 0) {
			remplirTableau(S, "1100101", 0, 7);
	} else if (strcmp(S, "SLL") == 0) {
			remplirTableau(S, "9000000", 0, 7);
	} else if (strcmp(S, "NOP\n") == 0) {
		/*Il y a un \n car comme il n'y a pas d'argument après un NOP, c'est un reste de ce que l'on récupère dans le fichier*/
			remplirTableau(S, "8000000", 0, 7);
	} else if (strcmp(S, "SRL") == 0) {
			remplirTableau(S, "B000010", 0, 7);
	} else if (strcmp(S, "ROTR") == 0) {
			remplirTableau(S, "A000010", 0, 7);
	} else if (strcmp(S, "SLT") == 0) {
			remplirTableau(S, "1101010", 0, 7);
	} else if (strcmp(S, "SW") == 0) {
			remplirTableau(S, "0101011", 0, 7);
	} else if (strcmp(S, "SUB") == 0) {
			remplirTableau(S, "1100010", 0, 7);
	} else if (strcmp(S, "XOR") == 0) {
			remplirTableau(S, "1100110", 0, 7);
	} else if (strcmp(S, "SYSCALL") == 0) {
			remplirTableau(S, "C001100", 0, 7);
	} else {
			remplirTableau(S, "111111", 0, 7);
	}
}


void remplirTableau (char S[], char bin[], int i, int j) {
	/* On remplit le tableau S de l'indice i à j avec des '0' et '1' pour créer un mot binaire. */
	
	int k;

	for (k = 0; i < j ; i++) {
		S[i] = bin[k];
		k++;
	}
	S[i] = '\0';
}


void decToBin (char S[], int nbrBits, int flagNegatif) {
	/* On converti un nombre décimal en binaire */
	int i;
	unsigned int nbr = 0;


	for(i = 0 ; S[i] != '\0' ; i++){
		nbr = nbr * 10 + (S[i] - '0');
	}
	
	/* Si le nombre est négatif, on fait le complément à 2 */
	if (flagNegatif == 1) {
		nbr = ~nbr +1;
	}

	S[nbrBits] = '\0';
	for (i = nbrBits-1 ; i >= 0 ; i--) {
		if (nbr % 2 == 1) {
			S[i] = '1';
			nbr = (nbr-1)/2;
		} else {
			S[i] = '0';
			nbr /= 2;
		}
	}
}


unsigned int binToDec (char S[]) {
	/* On converti un nombre binaire en décimal. */
	int i;
	unsigned int somme = 0;

	for (i=31 ; i >= 0 ; i--) {
		if (S[i] == '1') {
			somme += puissance(2, 31-i);
		}
	}

	return somme;
}


unsigned int puissance (unsigned int a, int b) {
	/* Retourne a à la puissance b */
	int i;
	unsigned int res = 1;

	for (i = 0 ; i < b ; i++) {
		res *= a;
	}

	return res;
}
