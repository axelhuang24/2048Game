/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure ajouter un objet si il y a encore l'espace
   */
void ajouter(int tab[100][100],int size){
	int i,j,srand,l,k;
	srand=rand()%16;
	l=srand/size;
	k=srand%size;
	if(tab[l][k]!=0)
		tab[l][k]=1;
	else{
		for(i=l; i<size; i=i+1){
			for(j=k; j<size; j=j+1){
				if(tab[i][j]==0){
					tab[i][j]=1;
					i=size;
					j=size;
				}
			}
		}
	}
	return ;
}