#ifndef __FILE_H__
#define __FILE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


void createFile(char adresse[]);
int readFile (char adresse[], char instructions[][MAX]);

#endif