
#ifndef MODELE_H
#define MODELE_H
#include <vector>
using namespace std;
const int GAUCHE = 7, DROITE = 4, HAUT = 8, BAS = 2;
typedef vector<vector<int> > Plateau;
struct PlateauScore {
	Plateau plateau;
	int score;
};
Plateau plateauVide();
Plateau plateauInitial();
int tireDeuxOuQuatre();
PlateauScore deplacementGauche(PlateauScore plateau);
PlateauScore deplacementDroite(PlateauScore plateau);
PlateauScore deplacementHaut(PlateauScore plateau); 
PlateauScore deplacementBas(PlateauScore plateau);
PlateauScore deplacement(PlateauScore plateau, int direction);
string dessine(Plateau g);
bool estTermine(PlateauScore plateau);
bool estGagnant(Plateau plateau);
#endif
