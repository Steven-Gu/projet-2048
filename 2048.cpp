#include<vector>
#include<iostream>
#include "modele.h"
using namespace std;

int main() {

    while (true) {
        
        PlateauScore plateau;
        plateau.plateau = plateauInitial();
        plateau.score = 0;
        dessine(plateau.plateau);
        while (not estTermine(plateau) and not estGagnant(plateau.plateau)) {
            char direct;
            cout << "Entrer commande:";
            cin >> direct;
            if (direct == 'a') {
                plateau = deplacement(plateau, GAUCHE);
            }
            else if (direct == 'd') {
                plateau = deplacement(plateau, DROITE);
            }
            else if (direct == 'w') {
                plateau = deplacement(plateau, HAUT);
            }
            else if (direct == 's') {
                plateau = deplacement(plateau, BAS);
            }
            dessine(plateau.plateau);
            cout << plateau.score << endl;
        }
        if (estTermine(plateau)) {
            cout << "Vous avez perdu." << endl;
        }
        else if (estGagnant(plateau.plateau)) {
            cout << "Vous avez gagné." << endl;
        }
    }


}

