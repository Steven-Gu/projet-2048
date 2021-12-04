#include<vector>
#include<iostream>
#include<ncurses.h>
#include<unistd.h>
#include "modele.h"
using namespace std;

#define KEY_q 113

int main(int argc, char*argv[]) {
    initscr();
    cbreak();
    noecho();

    curs_set(0);
    int height, width, start_y, start_x;
    getmaxyx(stdscr,height, width);
    start_y = start_x = 0;

    WINDOW * win = newwin(height, width, start_y, start_x);

    wrefresh(win);
    keypad(win,true);

    if(has_colors()){
        start_color();
        init_pair(1,COLOR_YELLOW,COLOR_WHITE);
    }else{
        wprintw(win,"Does not have color!");
        wrefresh(win);
        sleep(2);
        return -1;
    }
    wbkgd(win,COLOR_PAIR(1));
    PlateauScore plateau;
    plateau.plateau = plateauInitial();
    plateau.score = 0;
    wattron(win,COLOR_PAIR(1));
    mvwprintw(win,3,0,dessine(plateau.plateau).c_str());
    wrefresh(win);
    mvwprintw(win,0,0,"Saisir q pour quitter");
    wrefresh(win);
    bool terminate;
    terminate = true;



    while (not estTermine(plateau) and not estGagnant(plateau.plateau) and terminate ==true) {
        int d;
        d = wgetch(win);
        mvwprintw(win,1,0,"use up down left and right to control:");
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
        mvwprintw(win,2,0,"score:");
        mvwprintw(win,2,6,"  %d",plateau.score);
        wrefresh(win);
        if (estTermine(plateau)) {
            mvwprintw(win,12,0,"Vous avez perdu.");
            wrefresh(win);
            sleep(3);
                       
            plateau.plateau = plateauInitial();
            plateau.score = 1;
            mvwprintw(win,2,7,"      ");
            
        }
        else if (estGagnant(plateau.plateau)) {
            mvwprintw(win,12,0,"Vous avez gagné! Vous pouvez continuer.");
            wrefresh(win);        
        }
    }
    attroff(COLOR_PAIR(1));

    endwin();
}

