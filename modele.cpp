#include<vector>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<string>
#include"modele.h"
using namespace std;
typedef vector<vector<int> > Plateau;

//Produire un tableau vide
Plateau plateauVide() {
	Plateau plateau;
	plateau = Plateau(4);
	for (int i = 0; i < 4; i++) {
		plateau[i] = vector<int>(4);
		for(int j= 0; j< 4; j++){
			plateau[i][j]=0;
		}
	}
	return plateau;
}

//Initialiser un plateau vide et remplir deux espaces différents avec 2 ou 4 selon la probabilité.
Plateau plateauInitial() {
	Plateau plateau = plateauVide();
	int tuile1 = rand() % (16);
	int tuile2;
	do {
		tuile2 = rand() % (16);
	} while (tuile2 == tuile1);

	plateau[tuile1 / 4 ][tuile1 % 4] = tireDeuxOuQuatre();
	plateau[tuile2 / 4][tuile2 % 4] = tireDeuxOuQuatre();
	return plateau;
}

//La probabilité de générer 4 est de 1 sur 10, donc un nombre aléatoire de 0 à 10 générera 4 si le nombre est 0 et 2 s'il ne l'est pas.
int tireDeuxOuQuatre() {
	int valeur = rand() % (10);
	if (valeur == 0)
		return 4;
	else
		return 2;
}

PlateauScore deplacementGauche(PlateauScore plateau) {
	Plateau plateauOrigine = plateau.plateau;
	for (int i = 0; i < 4; i++) {
/*Chaque ligne est vérifiée de droite à gauche et si un 0 est rencontré, elle est déplacée à la fin.
 *Si nous vérifions de gauche à droite, il y aura des cas où nous ne pourrons pas déplacer le 0 à l'extrême droite. 
 *Par exemple (0, 0, 4, 0), le premier coup devient (0, 4, 0, 0), après quoi la position la plus à gauche du 0 ne sera pas vérifiée,
 *ce qui fait qu'il ne deviendra pas (4, 0, 0, 0).
 */
		for (int j = 2; j >= 0; j--) {
			if (plateau.plateau[i][j] == 0) {
				for (int k = j + 1; k < 4; k++) {
					plateau.plateau[i][k - 1] = plateau.plateau[i][k];
					plateau.plateau[i][k] = 0;
				}
			}
		}
/*Vérifier de gauche à droite, si l'élément actuel est égal à l'élément suivant, 
 *multiplier l'élément actuel par deux et augmenter le score correspondant,
 *l'élément suivant devient zéro et le déplacer à la fin.
 */
		for (int t = 0; t < 3; t++) {
			if (plateau.plateau[i][t] == plateau.plateau[i][t + 1]) {
				plateau.plateau[i][t] *= 2;
				plateau.score += plateau.plateau[i][t];
				plateau.plateau[i][t + 1] = 0;
				for (int p = t + 1; p < 3; p++) {
					plateau.plateau[i][p] = plateau.plateau[i][p + 1];
					plateau.plateau[i][p + 1] = 0;
				}
			}
		}
	}
//Si le coup est réussi, le plateau est modifié et 2 ou 4 sont ajoutés à un espace vide aléatoire.
	if (plateau.plateau != plateauOrigine) {
		int tuile = rand() % 16;
		while (plateau.plateau[tuile / 4][tuile % 4] != 0) {
			tuile = rand() % 16;
		}
		plateau.plateau[tuile / 4][tuile % 4] = tireDeuxOuQuatre();
	}
	return plateau;
}

//Similaire à la fonction deplacementGauche
PlateauScore deplacementDroite(PlateauScore plateau) {
	Plateau plateauOrigine = plateau.plateau;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <4 ; j++) {
			if (plateau.plateau[i][j] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					plateau.plateau[i][k + 1] = plateau.plateau[i][k];
					plateau.plateau[i][k] = 0;
				}
			}
		}
		for (int t = 3; t > 0; t--) {
			if (plateau.plateau[i][t] == plateau.plateau[i][t - 1]) {
				plateau.plateau[i][t] *= 2;
				plateau.score += plateau.plateau[i][t];
				plateau.plateau[i][t - 1] = 0;
				for (int p = t - 1; p > 0; p--) {
					plateau.plateau[i][p] = plateau.plateau[i][p - 1];
					plateau.plateau[i][p - 1] = 0;
				}
			}
		}
	}
	if (plateau.plateau != plateauOrigine) {
		int tuile = rand() % 16;
		while (plateau.plateau[tuile / 4][tuile % 4] != 0) {
			tuile = rand() % 16;
		}
		plateau.plateau[tuile / 4][tuile % 4] = tireDeuxOuQuatre();
	}
	
	return plateau;
}

//Similaire à la fonction deplacementGauche
PlateauScore deplacementHaut(PlateauScore plateau) {
	Plateau plateauOrigine = plateau.plateau;
	for (int j = 0; j < 4; j++) {
		for (int i = 2; i >= 0; i--) {
			if (plateau.plateau[i][j] == 0) {
				for (int k = i + 1; k < 4; k++) {
					plateau.plateau[k - 1][j] = plateau.plateau[k][j];
					plateau.plateau[k][j] = 0;
				}
			}
		}
		for (int t = 0; t < 3; t++) {
			if (plateau.plateau[t][j] == plateau.plateau[t + 1][j]) {
				plateau.plateau[t][j] *= 2;
				plateau.score += plateau.plateau[t][j];
				plateau.plateau[t + 1][j] = 0;
				for (int p = t + 1; p < 3; p++) {
					plateau.plateau[p][j] = plateau.plateau[p + 1][j];
					plateau.plateau[p + 1][j] = 0;
				}
			}
		}
	}
	if (plateau.plateau != plateauOrigine) {
		int tuile = rand() % 16;
		while (plateau.plateau[tuile / 4][tuile % 4] != 0) {
			tuile = rand() % 16;
		}
		plateau.plateau[tuile / 4][tuile % 4] = tireDeuxOuQuatre();
	}
	return plateau;
}

//Similaire à la fonction deplacementGauche
PlateauScore deplacementBas(PlateauScore plateau) {
	Plateau plateauOrigine = plateau.plateau;
	for (int j = 0; j < 4; j++) {
		for (int i = 1; i < 4; i++) {
			if (plateau.plateau[i][j] == 0) {
				for (int k = i - 1; k >= 0; k--) {
					plateau.plateau[k + 1][j] = plateau.plateau[k][j];
					plateau.plateau[k][j] = 0;
				}
			}
		}
		for (int t = 3; t > 0; t--) {
			if (plateau.plateau[t][j] == plateau.plateau[t - 1][j]) {
				plateau.plateau[t][j] *= 2;
				plateau.score += plateau.plateau[t][j];
				plateau.plateau[t - 1][j] = 0;
				for (int p = t - 1; p > 0; p--) {
					plateau.plateau[p][j] = plateau.plateau[p - 1][j];
					plateau.plateau[p - 1][j] = 0;
				}
			}
		}
	}
	if (plateau.plateau != plateauOrigine) {
		int tuile = rand() % 16;
		while (plateau.plateau[tuile / 4][tuile % 4] != 0) {
			tuile = rand() % 16;
		}
		plateau.plateau[tuile / 4][tuile % 4] = tireDeuxOuQuatre();
	}
	return plateau;
}

//Différentes fonctions de déplacement sont exécutées en fonction de la direction du mouvement
PlateauScore deplacement(PlateauScore plateau, int direction) {
  switch ( direction ) {
    case GAUCHE:
      return deplacementGauche(plateau);
    case DROITE:
      return deplacementDroite(plateau);
    case HAUT:
      return deplacementHaut(plateau);
    case BAS:
      return deplacementBas(plateau);
    default:
      cerr << "Deplacement non-autorise!" << endl;
      exit(-1);
  }
}
//Convertissez les entiers du tableau en chaînes de caractères, en les formatant pour l'impression en fonction de leur longueur.
string dessine(Plateau g) {
	stringstream ss;
	string dessine;
	ss<<"*************************"<<endl;
	for (int i = 0; i < 4; i++) {
        ss<<"*";
        for (int j = 0; j < 4; j++) {
			if (g[i][j] == 0){
				ss<<"     "<<"*";
			}else if (to_string(g[i][j]).length() == 1) {
                ss<<"  "<<g[i][j]<<"  "<<"*";
			}
			else if (to_string(g[i][j]).length() == 2) {
                ss<<" "<<g[i][j]<<"  "<<"*";
			}
			else if (to_string(g[i][j]).length() == 3) {
                ss<<" "<<g[i][j]<<" "<<"*";
			}
			else if (to_string(g[i][j]).length() == 4) {
                ss<<g[i][j]<<" "<<"*";
			}
            

		}
        ss<<endl<<"*************************"<<endl;
	}
    dessine = ss.str();
	return dessine;
}

//S'il y a des espaces sur le plateau ou si vous pouvez faire n'importe quel mouvement, le jeu n'est pas terminé.
bool estTermine(PlateauScore plateau) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (plateau.plateau[i][j] == 0)
				return false;
		}
	}
	if (plateau.plateau == deplacementBas(plateau).plateau
		and plateau.plateau==deplacementHaut(plateau) .plateau
		and plateau.plateau==deplacementDroite(plateau) .plateau
		and plateau.plateau==deplacementGauche(plateau).plateau) {
		return true;
	}
	return false;
}

//Si une cellule contient 2048, la partie est gagnée.
bool estGagnant(Plateau plateau) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (plateau[i][j] == 2048)
				return true;
		}
	}
	return false;
}
