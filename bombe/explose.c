/* @ requires tab est un tableau avec deux dimensions, i et j indiquent la position
   @ assigns 
   @ ensure exploser
   */
void explose(int tab[100][100],int i,int j){
	if(tab[i][j]=='+'){
		tab[i][j]=0;
		tab[i-1][j]=0;
		tab[i+1][j]=0;
		tab[i][j-1]=0;
		tab[i][j+1]=0;
	}

	if(tab[i][j]=='x'){
		tab[i][j]=0;
		tab[i-1][j-1]=0;
		tab[i+1][j+1]=0;
		tab[i-1][j+1]=0;
		tab[i+1][j-1]=0;
	}

	if(tab[i][j]=='*'){
		tab[i][j]=0;
		tab[i-1][j]=0;
		tab[i+1][j]=0;
		tab[i][j-1]=0;
		tab[i][j+1]=0;
		tab[i-1][j-1]=0;
		tab[i+1][j+1]=0;
		tab[i-1][j+1]=0;
		tab[i+1][j-1]=0;
	}

	return;
}