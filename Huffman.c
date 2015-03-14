#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "parseur.h"
#include "algo_huff.h"

int main(int argc,char* argv[]) {
	if (argc == 2) {
		int n_etat = nombre_etat(argv[1]);
		variable* vars = NULL;
		vars = malloc(n_etat*sizeof(variable));
		if (vars == NULL) {
			printf("Erreur d'allocation de memoire");
			return 1;
		}
		lecture(argv[1], n_etat, vars);
		for (int i=0; i < n_etat; i++) {
			printf("Etat: %d Proba: %f\n",(vars+i)->etat,(vars+i)->probabilite);
		}
		arbre* arbre_huff = NULL;
		arbre_huff = malloc(n_etat*sizeof(arbre));
		if (arbre_huff == NULL) {
			printf("Erreur d'allocation de memoire");
			return 1;
		}
		huff(n_etat, vars, arbre_huff);
		/*
		printf("Tri termine\n");
		for (int i=0; i < n_etat; i++) {
			printf("Etat: %d Proba: %f\n",(vars+i)->etat,(vars+i)->probabilite);
		}	
		*/
	}
	else
	{
		printf("Mauvais arguments");
		return 1;
	}	
}
