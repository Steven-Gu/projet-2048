#include<vector>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<string>
#include"modele.h"
using namespace std;
typedef vector<vector<int> > Plateau;

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
		for (int j = 2; j >= 0; j--) {
			if (plateau.plateau[i][j] == 0) {
				for (int k = j + 1; k < 4; k++) {
					plateau.plateau[i][k - 1] = plateau.plateau[i][k];
					plateau.plateau[i][k] = 0;
				}
			}
		}
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
	if (plateau.plateau != plateauOrigine) {
		int tuile = rand() % 16;
		while (plateau.plateau[tuile / 4][tuile % 4] != 0) {
			tuile = rand() % 16;
		}
		plateau.plateau[tuile / 4][tuile % 4] = tireDeuxOuQuatre();
	}
	return plateau;
}

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

bool estGagnant(Plateau plateau) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (plateau[i][j] == 2048)
				return true;
		}
	}
	return false;
}
