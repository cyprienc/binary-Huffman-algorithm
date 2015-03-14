#ifndef PARSEUR
#define PARSEUR
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct variable variable;

struct variable
{
	int etat;
	float probabilite;
};

int nombre_etat(char* nomfichier);

void lecture(char* nomfichier,int n_etats, variable* var);

#endif
