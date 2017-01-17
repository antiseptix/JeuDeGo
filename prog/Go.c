#include "dessine.h"
#include <math.h>

const float taille_case = 25.0;
const int nb_ligne = 19;
const int taille_boule = 7;

typedef struct Boule{
	int x;
	int y;
	int joueur;
	struct Boule* nextT;
	struct Boule* nextR;
	struct Boule* nextB;
	struct Boule* nextL;
} SBoule;

typedef struct Chaine{
	SBoule* tete;
	int nbBoule;
} SChaine;

/**
 * Mettre ici son code pour dessiner dans la fenetre
 * 1er affichage + redessine si resize
 */
void draw_win()
{	
	// vide la fenetre
	clear_win();

	int i,j;
	
	/*for(i=0; i<height_win()/2; i+=2)
	{
		for(j=0; j<width_win(); j+=2)
		{
			float r = (float)rand()/RAND_MAX;
			float v = (float)rand()/RAND_MAX;
			float b = (float)rand()/RAND_MAX;
			color(r,v,b);
			pixel(j,i);
		}
	}
		
	for(i=height_win()/2; i<height_win(); i+=4)
	{
		for(j=0; j<width_win(); j+=4)
		{
			float g = (float)rand()/RAND_MAX;
			color(g,g,g);
			filled_rectangle(j,i,4,4);
		}
	}*/


	color(1,0,0);
	for(i=taille_case; i< width_win(); i+=taille_case){
		for(j=taille_case; j<height_win(); j+=taille_case){
	// Ligne horizontale
			line(j,i, width_win()-j, i);
	// Ligne verticale
			line(j,i, j, width_win()-i);
		}
	}

	
	/*color(11,1,1);
	string(5,5,"Test Affichage chaine");*/

	
	
}

/*int arrondi(int dividende, int diviseur){
	float res = 0.0;
	res = dividende/diviseur;
	res = res * taille_case;
	return (int)
}*/

// Renvoie la bonne coordonnée en fonction de l'endroit du clic
int test_clique(int coord){
	float res = 0;
	// Test clique en dehors de la zone de jeu
	if(coord < taille_case)
		coord = taille_case;
	else if( coord > width_win() - taille_case)
		coord = width_win() - taille_case;
	else if(coord > height_win() - taille_case)
		height_win() - taille_case;

	res = round(coord/taille_case);
	res = res * taille_case;
	return (int)res;
}
// Creation de boule
void creer_boule(int x, int y, int taille){
	filled_circle(x,y,7);
	// TODO ne pas oublier de mettre à jour les valeurs des boules de mm couleur a cote pour creer une chaine
	// TODO conserver la boule dans la liste de toutes les boules! 

	
}
/**
 * on a cliqué a la souris:
 * bouton: 1,2,3,4,5,... : gauche, milieu, droit, molette, ...
 * x,y position
 */
void mouse_clicked(int bouton, int x, int y)
{
	printf("Bouton %d presse au coord. %d,%d \n",bouton,x,y);
	color( 1.0,0.0,1.0);
	int array_sudo[2][2] = {25,25,75,75};
	x = test_clique(x);
	y = test_clique(y);

	//printf("NEW coord. %d,%d \n",x,y);
	creer_boule(x,y,taille_boule);	
	
}



/**
 * on a appuyé sur une touche
 * code: code touche x11 (XK_...)
 * c caractère correspondant si caractere
 * x_souris,y_souris position de la souris
 */
void key_pressed(KeySym code, char c, int x_souris, int y_souris)
{
	switch(code)
	{
		case XK_Down:
			printf("bas\n");
			break;
		case XK_Up:
			printf("haut\n");
			break;
		case XK_Left:
			printf("gauche\n");
			break;
		case XK_Right:
			printf("droite\n");
			break;
	//~ case XK_Return:
	//~ case XK_Shift_L:
	//~ case XK_Control_R:
	//~ ....
		default:
			break;
	}
	
	if (c>' ' && c<'z')
		printf("char: %c \n",c);

	printf(" avec pos souris: %d,%d \n",x_souris,y_souris);

}


int main() 
{
	
	init_win((nb_ligne+1)*taille_case,(nb_ligne+1)*taille_case, "Jeu de Go",0.2,0.2,0.6);
	event_loop();
	return EXIT_SUCCESS;
}
