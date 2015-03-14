#ifndef ALGO_HUFF
#define ALGO_HUFF
#include <stdio.h>
#include <stdlib.h>
#include "parseur.h"

typedef struct arbre arbre;
struct arbre
{
	int etat;
	int codage;
};

typedef struct node node;
struct node
{
	int etat;
	int childs[2];
	float probability;
};

void huff(int n_etats, variable* var, arbre* arb_huff);

//void sorting_tree(int n_etats, variable* var);

//void sorting_nodes(int taille, node *node_l, int *node_s);
int fnd_lwst_avlble_prbblty(int taille, node *node_l, int *node_s,int *index1,int *index2);
//return:
// 0: ok
// -1: no place
// 1: one node


void generate_parent(int place,node *node_l,int *node_s,int *index1,int *index2);

#endif
