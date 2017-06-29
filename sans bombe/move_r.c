/* @ requires tab est un tableau avec deux dimensions, size est la taille
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction driote
   */
void move_r(int tab[100][100], int size){
	int i,j;
	for(i=0; i<size; i=i+1){
		for(j=size-2; j>0 || j==0; j=j-1){
			if(tab[i][j+1]==0){
				tab[i][j+1]=tab[i][j];
				tab[i][j]=0;				
			}
		}
	}
}