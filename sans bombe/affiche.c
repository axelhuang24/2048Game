#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure afficher le tableau
   */
void affiche(int tab[100][100], int size){
	int i,j,k;
	for(i=0; i<size; i=i+1){
		for(k=0; k<size; k=k+1){
			printf(" - ");
		}
		printf("\n");
		printf("|");
		for(j=0; j<size; j=j+1){
			printf("%d |",tab[i][j]);
		}
		printf("\n");
	}
	for(k=0; k<size; k=k+1){
			printf(" - ");
		}
	printf("\n");
	return ;
}
