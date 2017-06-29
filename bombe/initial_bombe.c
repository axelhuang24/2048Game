/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure initialiser le tableau (0=NULL)
   */
void initial(int tab[100][100], int size){
	int i,j,srand ;
	srand=rand()%(size*size) ;
	for(i=0; i<size; i=i+1){
		for(j=0; j<size; j=j+1){
			tab[i][j]=0;
		}
	}
	i=srand/size;
	j=srand%size;
	tab[i][j]=1;
	return ;
}