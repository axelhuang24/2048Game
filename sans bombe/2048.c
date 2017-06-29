#include <stdio.h>
#include <stdlib.h>


/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns 
   @ ensure afficher le tableau
   */
void affiche(int tab[100][100], int hauteur, int largeur){
	int i,j,k;
	for(i=0; i<hauteur; i=i+1){
		for(k=0; k<largeur; k=k+1){
			printf(" ---");
		}
		printf("\n");
		printf("|");
		for(j=0; j<largeur; j=j+1){
			printf(" %d |",tab[i][j]);
		}
		printf("\n");
	}
	for(k=0; k<largeur; k=k+1){
			printf(" ---");
		}
	printf("\n");
	return ;
}



/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns 
   @ ensure retourne le plus grand entier dans le tableau tab
   */
int maximum(int tab[100][100], int hauteur, int largeur){ 
	int sup,i,j;
	sup=tab[0][0];
	for(i=0; i<hauteur; i=i+1){
		for(j=0; j<largeur; j=j+1){
			if(sup<tab[i][j])
				sup=tab[i][j];
		}
	}
	return sup;
}


/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns tous les elements dans le tableau tab
   @ ensure initialiser le tableau (0=NULL)
   */

void initial(int tab[100][100], int hauteur, int largeur){
	int i,j,srand ;
	srand=rand()%(hauteur*largeur) ;
	for(i=0; i<hauteur; i=i+1){
		for(j=0; j<largeur; j=j+1){
			tab[i][j]=0;
		}
	}
	i=srand/largeur;
	j=srand%largeur;
	tab[i][j]=1;
	return ;
}




/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns ca depend des opposition des valeurs
   @ ensure tous les elements se deplacent dans la direction gauche
   */
void move_l(int tab[100][100], int hauteur, int largeur){
	int i,j;
	for(i=0; i<hauteur; i=i+1){
		for(j=1; j<largeur; j=j+1){
			if(tab[i][j-1]==0){
				tab[i][j-1]=tab[i][j];
				tab[i][j]=0;
			}
		}
	}
	return ;
}

/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des valeurs
   @ ensure tous les elements se deplacent dans la direction gauche et se confondent
   */
void move_left(int tab[100][100], int hauteur, int largeur){
	int i,j;
	
	/* tous les elements se deplacent dans la direction gauche */
	for(i=1; i<largeur; i++){
		move_l(tab,hauteur,largeur);
	}

	/* se confondre */
	for(i=0; i<hauteur; i=i+1){
		for(j=0; j<largeur; j=j+1){
			if(tab[i][j]==tab[i][j+1]){
				tab[i][j]=tab[i][j]+tab[i][j+1];
				tab[i][j+1]=0;
				j=j+1;
			}
		}
	}
	
    /* tous les elements se deplacent dans la direction gauche */
	for(i=1; i<largeur; i++){
		move_l(tab,hauteur,largeur);
	}

	return ;
}


/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des opposition des valeurs
   @ ensure tous les elements se deplacent dans la direction driote
   */
void move_r(int tab[100][100], int hauteur, int largeur){
	int i,j;
	for(i=0; i<hauteur; i=i+1){
		for(j=largeur-2; j>0 || j==0; j=j-1){
			if(tab[i][j+1]==0){
				tab[i][j+1]=tab[i][j];
				tab[i][j]=0;				
			}
		}
	}
	return ;
}

/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des valeurs
   @ ensure tous les elements se deplacent dans la direction droite et se confondent
   */
void move_right(int tab[100][100], int hauteur, int largeur){
	int i,j;
	
	/* tous les elements se deplacent dans la direction droite */
	for(i=1; i<largeur; i++){
		move_r(tab,hauteur,largeur);
	}

	/* se confondre */
	for(i=0; i<hauteur; i=i+1){
		for(j=largeur-1; j>0 || j==0; j=j-1){
			if(tab[i][j]==tab[i][j-1]){
				tab[i][j]=tab[i][j]+tab[i][j-1];
				tab[i][j-1]=0;
				j=j-1;
			}
		}
	}
	
	/* tous les elements se deplacent dans la direction droite */
	for(i=1; i<largeur; i++){
		move_r(tab,hauteur,largeur);
	}

	return ;
}


/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des opposition des valeurs
   @ ensure tous les elements se deplacent dans la direction haut
   */
void move_u(int tab[100][100], int hauteur, int largeur){
	int i,j;
	for(j=0; j<largeur; j=j+1){
		for(i=1; i<hauteur; i=i+1){
			if(tab[i-1][j]==0){
				tab[i-1][j]=tab[i][j];
				tab[i][j]=0;
			}
		}
	}
	return ;
}

/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des valeurs
   @ ensure tous les elements se deplacent dans la direction haut et se confondent
   */
void move_up(int tab[100][100], int hauteur, int largeur){
	int i,j;
	
	/* tous les elements se deplacent dans la direction haut */
	for(i=1; i<hauteur; i++){
		move_u(tab,hauteur,largeur);
	}

	/* se confondre */
	for(j=0; j<largeur; j=j+1){
		for(i=0; i<hauteur; i=i+1){
			if(tab[i][j]==tab[i+1][j]){
				tab[i][j]=tab[i][j]+tab[i+1][j];
				tab[i+1][j]=0;
				i=i+1;
			}
		}
	}
	
	/* tous les elements se deplacent dans la direction haut */
	for(i=1; i<hauteur; i++){
		move_u(tab,hauteur,largeur);
	}

	return ;
}


/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des opposition des valeurs
   @ ensure tous les elements se deplacent dans la direction bas
   */
void move_d(int tab[100][100], int hauteur, int largeur){
	int i,j;
	
	for(j=0; j<largeur; j=j+1){
		for(i=hauteur-2; i>0 || i==0; i=i-1){
			if(tab[i+1][j]==0){
				tab[i+1][j]=tab[i][j];
				tab[i][j]=0;				
			}
		}
	}
	return ;
}


/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  ca depend des valeurs
   @ ensure tous les elements se deplacent dans la direction bas et se confondent
   */
void move_down(int tab[100][100], int hauteur, int largeur){
	int i,j;
	
	/* tous les elements se deplacent dans la direction bas */
	for(i=1; i<hauteur; i++){
		move_d(tab,hauteur,largeur);
	}

	/* se confondre */
	for(j=0; j<largeur; j=j+1){
		for(i=hauteur-1; i>0 || i==0; i=i-1){
			if(tab[i][j]==tab[i-1][j]){
				tab[i][j]=tab[i][j]+tab[i-1][j];
				tab[i-1][j]=0;
				i=i-1;
			}
		}
	}
	
	/* tous les elements se deplacent dans la direction bas */
	for(i=1; i<hauteur; i++){
		move_d(tab,hauteur,largeur);
	}

	return ;
}



/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns  1 opposition aleatoire
   @ ensure ajouter un objet si il y a encore l'espace
   */
void ajouter(int tab[100][100], int hauteur, int largeur){
	int i,j,srand,l,k;
	srand=rand()%(largeur*hauteur);
	l=srand/largeur;
	k=srand%largeur;
	if(tab[l][k]==0)
		tab[l][k]=1;
	else{
		for(i=l; i<hauteur; i=i+1){
			for(j=k; j<largeur; j=j+1){
				if(tab[i][j]==0){
					tab[i][j]=1;
					i=hauteur;
					j=largeur;
				}
			}
		}
	}
	return ;
}





/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille
   @ assigns 
   @ ensure tester si le tab est full et si il devient impossible de faire evoluer la situation
     si c'est vrai, retourne 1 et 0 sinon
   */
int Isfull(int tab[100][100], int hauteur, int largeur){
	int i,j;
	/* tester s'il est borne */
	for(i=0; i<hauteur; i=i+1){
		for(j=0; j<largeur; j=j+1){
			if(tab[i][j]==0)
				return 0;
		}
	}
	/* tester s'il devient imposiible de faire evoluer la situation */
	/* la premiere ligne, testez s'il egal au element au dessous, et retourne 0 si c'est vrai */
	for(j=0; j<largeur; j=j+1){
		if(tab[0][j]==tab[1][j])
			return 0;
	}
	/* la derniere ligne, testez s'il egal au element au dessus, et retourne 0 si c'est vrai */
	for(j=0; j<largeur; j=j+1){
		if(tab[hauteur-1][j]==tab[hauteur-2][j])
			return 0;
	}
	/* la premiere colonne, testez s'il egal au element a droite, et retourne 0 si c'est vrai */
	for(i=0; i<hauteur; i=i+1){
		if(tab[i][0]==tab[i][1])
			return 0;
	}
	/* la derniere colonne, testez s'il egal au element a gauche, et retourne 0 si c'est vrai */
	for(i=0; i<hauteur; i=i+1){
		if(tab[i][largeur-1]==tab[i][largeur-2])
			return 0;
	}
	/* les elements centre, testez s'il egal au un des elements entourees, et retourne 0 si c'est vrai */
	for(i=1; i<hauteur-1; i=i+1){
		for(j=1; j<largeur-1; j=j+1){
			if( (tab[i][j]==tab[i][j-1]) || (tab[i][j]==tab[i][j+1]) || (tab[i][j]==tab[i-1][j]) || (tab[i][j]==tab[i+1][j])  )
				return 0;
		}
	}
	return 1;
}



/* @ requires tab est un tableau avec deux dimensions, hauteur et largeur est la taille£¬et but est la valeur fixee avant
   @ assigns 
   @ ensure retourne 1 si il parvient la valeur fixee avant et 0 sinon
   */
void parvient(int tab[100][100], int hauteur, int largeur, int but){ 
	int i,j;
	for(i=0; i<hauteur; i=i+1){
		for(j=0; j<largeur; j=j+1){
			if(tab[i][j]>but || tab[i][j]==but){
				printf("Bravo, vous gagnez la partie !\n");
				printf("\n");
				return ;
			}
		}
	}
	return ;
}


/* fonction main */
int main(){
	int but,hauteur,largeur;
	int tab[100][100];
	char c,c1;
	char buffer[2];
    
	/* demander la taille */
	printf("Vous preferez le tableau avec quelle taille(hauteur) : (MAX=100) ?\n");
	scanf("%d",&hauteur); 
	printf("Vous preferez le tableau avec quelle taille(largeur) : (MAX=100) ?\n");
	scanf("%d",&largeur); 

	printf(" Let's start the game !\n");

	printf("Entrez un entier(votre but, comme : 16,32,64,128 ,,,,), svp :\n"); /* demander le but */
	scanf("%d",&but);
	printf("Le but est %d\n",but);

    /* Let's start the game */
	initial(tab,hauteur,largeur); /* Initialisation */
	printf("Initialisation:\n");
	affiche(tab,hauteur,largeur);

	while( (!Isfull(tab,hauteur,largeur)) && ( (maximum(tab,hauteur,largeur))<but ) ){  /* si il parvient le but ou le tableau est rempli , la boucle est finie */
		printf("Entrez la direction, svp : j(left), l(right), i(up), k(down),svp .\n"); /* demander la direction */
		scanf("%1s",buffer);
		c=buffer[0];
		c1=c;
		if(c=='e') return 0;
		else if( c!='i' && c!='j' && c!='k' && c!='l'){
			printf("Faute de saisie ! \n(Si vous voulez exit,entrez 'e',svp !)\n");
	     	printf("(Si vous voulez continuer,entrez 'i' ou 'j' ou 'k' ou 'l',svp !)\n");
			continue;
		}

		printf("Vous etes sur que vous voulez se deplacer dans direction %c ?\n",c); /* demander la confirmation de direction */
		scanf("%1s",buffer);
		c=buffer[0];
		if(c!='y'){
			printf("Le tableau ne se deplace pas.\n"); /* non confirmee */
			continue;
		}			
		else{  /* confirmee */
			
			if(c1=='j') { move_left(tab,hauteur,largeur) ; ajouter(tab,hauteur,largeur); }
				
			else if(c1=='l') {move_right(tab,hauteur,largeur) ; ajouter(tab,hauteur,largeur);}
				
			else if(c1=='i') {move_up(tab,hauteur,largeur) ; ajouter(tab,hauteur,largeur);}
				
			else if(c1=='k') {move_down(tab,hauteur,largeur) ; ajouter(tab,hauteur,largeur);}

			affiche(tab,hauteur,largeur); /* afficher le tableau */

		/* tester si le tab est full et si il devient impossible de faire evoluer la situation  */
		if( Isfull(tab,hauteur,largeur) )
			printf("Dommage, vous avez perdu la partie !\n");

		/* si il parvient la valeur fixee avant */
		parvient(tab,hauteur,largeur,but); 
		}
	}
	return 0 ;
}
