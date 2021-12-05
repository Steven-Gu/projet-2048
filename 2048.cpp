#include<vector>
#include<iostream>
#include<ncurses.h>
#include<unistd.h>
#include "modele.h"
using namespace std;

#define KEY_q 113

int main(int argc, char*argv[]) {
    //Initialisation de l'écran
    initscr();    
    //désactive la mise en mémoire tampon des lignes, rendant les caractères tapés par l'utilisateur immédiatement disponibles pour le programme.
    cbreak();
    //désactiver l'écho des caractères tapés par l'utilisateur
    noecho();
    //Cacher le curseur
    curs_set(0);
    int height, width, start_y, start_x;
    //Obtenez la longueur et la largeur de l'écran et attribuez-les à height et width
    getmaxyx(stdscr,height, width);
    start_y = start_x = 0;
    //Créer une nouvelle fenêtre
    WINDOW * win = newwin(height, width, start_y, start_x);
    //Rafraîchir la fenêtre
    wrefresh(win);
    //Permet la lecture d'un clavier externe
    keypad(win,true);
    //Vérifiez si le terminal supporte l'attribut de couleur, si c'est le cas, définissez le style 1 de couleur à jaune-blanc, sinon, quittez.
    if(has_colors()){
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_WHITE);
    }else{
        wprintw(win,"Does not have color!");
        wrefresh(win);
        sleep(2);
        return -1;
    }
    //Définissez la couleur de fond sur le style de couleur 1
    wbkgd(win,COLOR_PAIR(1));
    //Initialisation du plateau de jeu
    PlateauScore plateau;
    plateau.plateau = plateauInitial();
    plateau.score = 0;
    //Activez les couleurs dans la fenêtre
    wattron(win,COLOR_PAIR(1));
    //Imprimez le plateau de jeu sur la troisième ligne de la fenêtre.
    mvwprintw(win,3,0,dessine(plateau.plateau).c_str());
    wrefresh(win);
    //Imprimer un message de rappel en haut de la fenêtre
    mvwprintw(win,0,0,"Saisir q pour quitter");
    wrefresh(win);

    while (not estTermine(plateau) and not estGagnant(plateau.plateau)) {
        int d;
        //Lire un caractère du clavier et le stocker dans d
        d = wgetch(win);
        mvwprintw(win,1,0,"use up down left and right to control:");
        //Écraser le message de fin original après le début d'une nouvelle partie.
        mvwprintw(win,12,0,"                                                       ");
        wrefresh(win);
        if (d==KEY_LEFT){
                wrefresh(win);
                plateau = deplacement(plateau, GAUCHE);
        }else if(d==KEY_RIGHT){
                wrefresh(win);
                plateau = deplacement(plateau, DROITE);
        }else if(d==KEY_UP){
                wrefresh(win);
                plateau = deplacement(plateau, HAUT);
        }else if(d==KEY_DOWN){
                wrefresh(win);
                plateau = deplacement(plateau, BAS);
        }else if(d==KEY_q){

            break;
        }
        mvwprintw(win,3,0,dessine(plateau.plateau).c_str());
        //Imprimer le score actuel
        mvwprintw(win,2,0,"score:");
        mvwprintw(win,2,6,"  %d",plateau.score);
        wrefresh(win);
        if (estTermine(plateau)) {
            mvwprintw(win,12,0,"Vous avez perdu. Vous pouvez relancer en 3 secondes.");
            wrefresh(win);
            //Maintient l'état actuel de l'écran pendant 3 secondes
            sleep(3);
                       
            plateau.plateau = plateauInitial();
            plateau.score = 0;
            mvwprintw(win,2,7,"      ");
            
        }
        else if (estGagnant(plateau.plateau)) {
            mvwprintw(win,12,0,"Vous avez gagné! Vous pouvez continuer en 3 secondes.");
            wrefresh(win);        
        }
    }
    //Desactivez les couleurs dans la fenêtre
    attroff(COLOR_PAIR(1));

    endwin();
}

