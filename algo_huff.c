#include <stdio.h>
#include <stdlib.h>
#include "algo_huff.h"
#include "parseur.h"

void huff(int n_etats, variable* var, arbre* arb_huff) {
	node node_list[(2*n_etats)-1];
	//sorting_tree(n_etats, var);
	int node_sortable[(2*n_etats)-1];
	int i;
	for (i=0; i<n_etats; i++) {
		node_list[i].etat = (var+i)->etat;
		node_list[i].childs[0] = -1;
		node_list[i].childs[1] = -1;
		node_list[i].probability = (var+i)->probabilite;
		node_sortable[i] = 0;
	}
	int min1, min2;
	int res;
	for (;i < (2*n_etats)-1; i++) {
		res = fnd_lwst_avlble_prbblty(i, node_list, node_sortable, &min1, &min2);
		//printf("Child: %d %d\n",min1,min2);
		if ( res != -1 ) {
			//printf("Place: %d\n",i);
			generate_parent(i, node_list, node_sortable, &min1, &min2);
		}		
	}
	/*for (int j = 0; j < (2*n_etats)-1; j++) {
		printf("Etat: %d childs: %d %d probabilty: %f\n",node_list[j].etat,node_list[j].childs[0]+1,node_list[j].childs[1]+1,node_list[j].probability);
		}*/
}


int fnd_lwst_avlble_prbblty(int taille, node *node_l, int *node_s,int *index1,int *index2) {
	int i = 0;
	while (node_s[i] == 1 && i < taille) {
		i++;
	}
	if (i == taille && node_s[i] == 1) {
		return -1; //nothing found
	}	
	*index1 = i;
	i++;
	while (node_s[i] == 1 && i < taille) {
		i++;
	}
	*index2 = i;	
	if (node_l[*index1].probability > node_l[*index2].probability) {
		int temp = *index1;
		*index1 = *index2;
		*index2 = temp;
	}
	i++;
	// putting i=0 for good measures.
	for (;i < taille; i++) {
		//printf("Node_s[%d] = %d\n", i, node_s[i]);
		//printf("Comparing: %f < %f => %d\n",node_l[i].probability,node_l[*index2].probability,(node_l[i].probability < node_l[*index2].probability && node_s[i] == 0));
		if ( node_l[i].probability < node_l[*index2].probability && node_s[i] == 0 ) {
			if ( node_l[i].probability <= node_l[*index1].probability ) {
				*index2 = *index1;
				*index1 = i;
			}
			else {
				*index2 = i;
			}
		}
	}
	return 0;
}
	
void generate_parent(int place,node *node_l,int *node_s,int *index1,int *index2) {
	node_s[*index1] = 1;
	node_s[*index2] = 1;
	node_s[place] = 0;
	node_l[place].etat = place+1;
	node_l[place].childs[0] = *index1;
	node_l[place].childs[1] = *index2;
	node_l[place].probability = (node_l + *index1)->probability + (node_l + *index2)->probability;
}
