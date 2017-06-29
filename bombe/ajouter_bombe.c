/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure ajouter un objet si il y a encore l'espace
   */
void ajouter_bombe(int tab[100][100],int size){
	int i,j,srand1,l,k,srand2;
	srand1=rand()%(size*size);
	l=srand1/size; /* ligne */
	k=srand1%size; /* colonne */
	
	if(tab[l][k]==0){
		if( maximum(tab,size)<65 )  /* si max<=64 */
			tab[l][k]=1;
		else if( maximum(tab,size)>64 &&  maximum(tab,size)<256 ){  /* si 64<max<256 */
			srand2=rand()%100;
			if(srand2 < 70)
				tab[l][k]=1;
			else if(srand2 > 69 && srand2 < 90)
				tab[l][k]=2;
			else
				tab[l][k]='+';
		}
		else{   /* si max>=256 */
			srand2=rand()%100;
			if(srand2 < 60)
				tab[l][k]=1;
			else if(srand2 > 59 && srand2 < 85)
				tab[l][k]=2;
			else if(srand2 > 84 && srand2 < 95)
				tab[l][k]='+';
			else
				tab[l][k]='*';
		}
	}

	else{
		for(i=l; i<size; i=i+1){
			for(j=k; j<size; j=j+1){
				if(tab[i][j]==0){
					if( maximum(tab,size)<65 )  /* si max<=64 */
	             		tab[l][k]=1; 
	            	else if( maximum(tab,size)>64 &&  maximum(tab,size)<256 ){  /* si 64<max<256 */
		            	srand2=rand()%100;
		            	if(srand2 < 70)
			            	tab[l][k]=1;
		            	else if(srand2 > 69 && srand2 < 90)
			            	tab[l][k]=2;
			            else
			            	tab[l][k]='+';
					}


	            	else{   /* si max>=256 */
		            	srand2=rand()%100;
		            	if(srand2 < 60)
			            	tab[l][k]=1;
		             	else if(srand2 > 59 && srand2 < 85)
			            	tab[l][k]=2;
		             	else if(srand2 > 84 && srand2 < 95)
			            	tab[l][k]='+';
		             	else
			            	tab[l][k]='*';
					}
					i=size;
					j=size;
				}
			}
		}
	}
	return ;
}