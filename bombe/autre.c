/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure retourne le plus grand entier dans le tableau tab
   */
int max(int tab[][], int size){
	int sup,i,j;
	sup=tab[0][0];
	for(i=0; i<size; i=i+1){
		for(j=0; j<size; j=j+1){
			if(sup<tab[i][j])
				sup=tab[i][j];
		}
	}
	return sup;
}

/* @ requires tab est un tableau avec deux dimensions, size est la taille d'une dimension
   @ assigns 
   @ ensure tester si le tab est full et si il devient impossible de faire evoluer la situation
     si c'est vrai, retourne 1 et 0 sinon
   */
int Isfull(int tab[][], int size){
	int i,j;
	/* tester s'il bouree */
	for(i=0; i<size; i=i+1){
		for(j=0; j<size; j=j+1){
			if(tab[i][j]==NULL)
				return 0;
		}
	}
	/* tester s'il devient imposiible de faire evoluer la situation */
	/* la premiere ligne, testez s'il egal au element au dessous, et retourne 0 si c'est vrai */
	for(j=0; j<size; j=j+1){
		if(tab[0][j]=tab[1][j])
			return 0;
	}
	/* la derniere ligne, testez s'il egal au element au dessus, et retourne 0 si c'est vrai */
	for(j=0; j<size; j=j+1){
		if(tab[size-1][j]=tab[size-2][j])
			return 0;
	}
	/* la premiere colonne, testez s'il egal au element a droite, et retourne 0 si c'est vrai */
	for(i=0; i<size; i=i+1){
		if(tab[i][0]=tab[i][1])
			return 0;
	}
	/* la derniere colonne, testez s'il egal au element a gauche, et retourne 0 si c'est vrai */
	for(i=0; i<size; i=i+1){
		if(tab[i][size-1]=tab[i][size-2])
			return 0;
	}
	/* les elements centre, testez s'il egal au un des elements entourees, et retourne 0 si c'est vrai */
	for(i=1; i<size-1; i=i+1){
		for(j=1; j<size-1; j=j+1){
			if( (tab[i][j]=tab[i][j-1]) || (tab[i][j]=tab[i][j+1]) || (tab[i][j]=tab[i-1][j]) || (tab[i][j]=tab[i+1][j])  )
				return 0;
		}
	}
	return 1;
}