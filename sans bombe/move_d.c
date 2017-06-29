/* @ requires tab est un tableau avec deux dimensions, size est la taille
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction haut
   */
void move_u(int tab[100][100], int size){
	int i,j;
	
	for(j=0; j<size; j=j+1){
		for(i=size-2; i>0 || i==0; i=i-1){
			if(tab[i+1][j]==0){
				tab[i+1][j]=tab[i][j];
				tab[i][j]=0;				
			}
		}
	}

	return ;
}