#include "registre.h"


int main (int argc, char *argv[]) {
	int a,b;
	
	initRegistre ();
	
	a =  lectureRegistre (16);
	
	ecritureRegistre (0, 45);
	b = lectureRegistre (0);
	
	printf("a = %d\nb = %d\n", a,b);
	
	afficherRegistre();
	
	return 0;
}