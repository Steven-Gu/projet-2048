#ifndef MODELE_H__
#define MODELE_H__
#include <vector>
using namespace std;
const int GAUCHE = 7, DROITE = 4, HAUT = 8, BAS = 2;
typedef vector<vector<int>> Plateau;
//Une structure contenant le plateau et le score, le score étant mis à jour en temps réel à chaque coup.
struct PlateauScore {
	Plateau plateau;
	int score;
};

/** génère un Plateau de dimensions 4*4 ne contenant que des 0
 *  @return un Plateau vide
 **/
Plateau plateauVide();

/** génère deux nombres sur des cases aléatoires d'un Plateau vide
 *  @return un Plateau en début de jeu
 **/
Plateau plateauInitial();

/** génère aléatoirement un 2 ou un 4 avec des probabilités respectives de 9/10 et 1/10
 *  @return 2 ou 4
 **/
int tireDeuxOuQuatre();

/** déplace les tuiles d'un Plateau vers la gauche et les combine si possible
 *  @param plateau la stucture PlateauScore
 *  @return le PlateauScore une fois déplacé vers la gauche
 **/
PlateauScore deplacementGauche(PlateauScore plateau);

/** déplace les tuiles d'un Plateau vers la droite et les combine si possible
 *  @param plateau la stucture PlateauScore
 *  @return le PlateauScore une fois déplacé vers la droite
 **/
PlateauScore deplacementDroite(PlateauScore plateau);

/** déplace les tuiles d'un Plateau vers le haut et les combine si possible
 *  @param plateau la stucture PlateauScore
 *  @return le PlateauScore une fois déplacé vers le haut
 **/
PlateauScore deplacementHaut(PlateauScore plateau);

/** déplace les tuiles d'un Plateau vers le bas et les combine si possible
 *  @param plateau la stucture PlateauScore
 *  @return le PlateauScore une fois déplacé vers le bas
 **/
PlateauScore deplacementBas(PlateauScore plateau);

/** déplace les tuiles d'un Plateau dans la direction donnée et génère une nouvelle tuile si le déplacement est valide
 *  @param plateau la stucture PlateauScore
 *  @param direction la direction
 *  @return le PlateauScore déplacé dans la direction
 **/
PlateauScore deplacement(PlateauScore plateau, int direction);

/** affiche un Plateau
 * @param p le Plateau
 **/
string dessine(Plateau g);

/** permet de savoir si une partie est terminée
 *  @param plateau un Plateau
 *  @return true si une partie est terminée, false sinon
 **/
bool estTermine(PlateauScore plateau);

/** permet de savoir si une partie est gagnée
 * @param plateau la stucture PlateauScore
 * @return true si le plateau contient un 2048, false sinon
 **/
bool estGagnant(Plateau plateau);
#endif