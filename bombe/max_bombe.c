/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure retourne le plus grand entier dans le tableau tab
   */
int maximum(int tab[100][100], int size){ //wrong
	int sup,i,j;
	sup=tab[0][0];
	for(i=0; i<size; i=i+1){
		for(j=0; j<size; j=j+1){
			if(tab[i][j]!='+' && tab[i][j]!='x' && tab[i][j]!='*')
				if(sup<tab[i][j])
					sup=tab[i][j];
		}
	}
	return sup;
}