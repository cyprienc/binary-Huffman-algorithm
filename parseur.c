#include <stdio.h>
#include <stdlib.h>
#include "parseur.h"
#define MAX_SIZE 100

int nombre_etat(char* nomfichier) {
	FILE* fichier = NULL;
	int nombre = 0;
	fichier = fopen(nomfichier, "r");
	if (fichier != NULL) {
		fscanf(fichier, "%d", &nombre);
		fclose(fichier);
		return nombre;
	}
	else {
		printf("Erreur d'ouverture du fichier!");
		return 0;
	}
}

void lecture(char* nomfichier,int n_etats,variable* var) {
	FILE* fichier = NULL;
	fichier = fopen(nomfichier, "r");	
	if (fichier != NULL) {
		char skip_line[MAX_SIZE];
		fgets(skip_line, MAX_SIZE, fichier);
		for (int i=0; i < n_etats; i++) {
			char etat[MAX_SIZE];
			fgets(etat, MAX_SIZE, fichier);
			sscanf(etat, "%d", &(var+i)->etat);
			//(var+i)->etat = atoi(etat);
			//printf("Etat lu: %d\n", (var+i)->etat);
			char proba[MAX_SIZE];
			fgets(proba, MAX_SIZE, fichier);
			sscanf(proba, "%f", &(var+i)->probabilite);
			//(var+i)->probabilite = atof(proba);
			//printf("proba lu: %f\n", (var+i)->probabilite);
			//fgets(skip_line, MAX_SIZE, fichier);
		}
	}
	else {
		printf("Erreur d'ouverture du fichier!");
	}
}
