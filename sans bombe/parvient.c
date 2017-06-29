/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension£¬et but est la valeur fixee avant
   @ assigns 
   @ ensure retourne 1 si il parvient la valeur fixee avant et 0 sinon
   */
void parvient(int tab[100][100], int size, int but){ // wrong
	int i,j;
	for(i=0; i<size; i=i+1){
		for(j=0; j<size; j=j+1){
			if(tab[i][j]==but){
				printf("Vous gagnez la partie");
				return ;
			}
		}
	}
	printf("\n");
	return ;
}
