/* @ requires tab est un tableau avec deux dimensions, size est la taille
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction gauche
   */
void move_l(int tab[100][100], int size){
	int i,j;
	for(i=0; i<size; i=i+1){
		for(j=1; j<size; j=j+1){
			if(tab[i][j-1]==0){
				tab[i][j-1]=tab[i][j];
				tab[i][j]=0;
			}
		}
	}
	return ;
}


/* @ requires tab est un tableau avec deux dimensions, d est la direction(un char)
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction gauche et se confondent
   */
void move_left(int tab[100][100], int size){
	int i,j;
	
	/* tous les elements se deplacent dans la direction gauche */
	for(i=1; i<size; i++){
		move_l(tab,size);
	}

	/* se confondre */
	for(i=0; i<size; i=i+1){
		for(j=0; j<size; j=j+1){
			if( tab[i][j]!='+' && tab[i][j]!='x' && tab[i][j]!='*' ) /* si il est un nombre */
				if(tab[i][j]==tab[i][j+1]){
					tab[i][j]=tab[i][j]+tab[i][j+1];
			    	tab[i][j+1]=0;
				    j=j+1;
				}
			else /* si il est un bombe */
				if(tab[i][j]==tab[i][j+1]){
					if(tab[i][j]=='+')
						tab[i][j]='x';
					if(tab[i][j]=='x')
						tab[i][j]='*';
					if(tab[i][j]=='*'){explose(tab,i,j);return;}
			    	tab[i][j+1]=0;
				    j=j+1;
				}
		}
	}
	
    /* tous les elements se deplacent dans la direction gauche */
	for(i=1; i<size; i++){
		move_l(tab,size);
	}

	return ;
}


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
	return ;
}


/* @ requires tab est un tableau avec deux dimensions, d est la direction(un char)
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction droite et se confondent
   */
void move_right(int tab[100][100], int size){
	int i,j;
	
	/* tous les elements se deplacent dans la direction droite */
	for(i=1; i<size; i++){
		move_r(tab,size);
	}

	/* se confondre */
	for(i=0; i<size; i=i+1){
		for(j=size-1; j>0 || j==0; j=j-1){
			if( tab[i][j]!='+' && tab[i][j]!='x' && tab[i][j]!='*' ){ /* si il est un nombre */
				if(tab[i][j]==tab[i][j-1]){
			    	tab[i][j]=tab[i][j]+tab[i][j-1];
			    	tab[i][j-1]=0;
			    	j=j-1;
				}
			}
			else /* si il est un bombe */
				if(tab[i][j]==tab[i][j-1]){
					if(tab[i][j]=='+')
						tab[i][j]='x';
					if(tab[i][j]=='x')
						tab[i][j]='*';
					if(tab[i][j]=='*'){explose(tab,i,j);return;}
			    	tab[i][j-1]=0;
				    j=j-1;
				}
			
		}
	}
	
	/* tous les elements se deplacent dans la direction droite */
	for(i=1; i<size; i++){
		move_r(tab,size);
	}

	return ;
}


/* @ requires tab est un tableau avec deux dimensions, size est la taille
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction haut
   */
void move_u(int tab[100][100], int size){
	int i,j;
	for(j=0; j<size; j=j+1){
		for(i=1; i<size; i=i+1){
			if(tab[i-1][j]==0){
				tab[i-1][j]=tab[i][j];
				tab[i][j]=0;
			}
		}
	}
	return ;
}


/* @ requires tab est un tableau avec deux dimensions, d est la direction(un char)
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction haut et se confondent
   */
void move_up(int tab[100][100], int size){
	int i,j;
	
	/* tous les elements se deplacent dans la direction haut */
	for(i=1; i<size; i++){
		move_u(tab,size);
	}

	/* se confondre */
	for(j=0; j<size; j=j+1){
		for(i=0; i<size; i=i+1){
			if( tab[i][j]!='+' && tab[i][j]!='x' && tab[i][j]!='*' ){ /* si il est un nombre */
				if(tab[i][j]==tab[i+1][j]){
			    	tab[i][j]=tab[i][j]+tab[i+1][j];
			    	tab[i+1][j]=0;
			    	i=i+1;
				}
			}
			else /* si il est un bombe */
				if(tab[i][j]==tab[i+1][j]){
					if(tab[i][j]=='+')
						tab[i][j]='x';
					if(tab[i][j]=='x')
						tab[i][j]='*';
					if(tab[i][j]=='*'){explose(tab,i,j);return;}
			    	tab[i+1][j]=0;
				    i=i+1;
				}
			
		}
	}

	/* tous les elements se deplacent dans la direction haut */
	for(i=1; i<size; i++){
		move_u(tab,size);
	}

	return ;
}


/* @ requires tab est un tableau avec deux dimensions, size est la taille
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction bas
   */
void move_d(int tab[100][100], int size){
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


/* @ requires tab est un tableau avec deux dimensions, d est la direction(un char)
   @ assigns 
   @ ensure tous les elements se deplacent dans la direction bas et se confondent
   */
void move_down(int tab[100][100], int size){
	int i,j;
	
	/* tous les elements se deplacent dans la direction bas */
	for(i=1; i<size; i++){
		move_d(tab,size);
	}

	/* se confondre */
	for(j=0; j<size; j=j+1){
		for(i=size-1; i>0 || i==0; i=i-1){
			if( tab[i][j]!='+' && tab[i][j]!='x' && tab[i][j]!='*' ){ /* si il est un nombre */
				if(tab[i][j]==tab[i-1][j]){
			    	tab[i][j]=tab[i][j]+tab[i-1][j];
			    	tab[i-1][j]=0;
			    	i=i-1;
				}
			}
			else /* si elle est une bombe */
				if(tab[i][j]==tab[i-1][j]){
					if(tab[i][j]=='+')
						tab[i][j]='x';
					if(tab[i][j]=='x')
						tab[i][j]='*';
					if(tab[i][j]=='*'){explose(tab,i,j);}//return;
			    	tab[i-1][j]=0;
				    i=i-1;
				}
		}
	}
	
	/* tous les elements se deplacent dans la direction bas */
	for(i=1; i<size; i++){
		move_d(tab,size);
	}

	return ;
}