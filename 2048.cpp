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
        init_pair(2,COLOR_CYAN,COLOR_WHITE);
        init_pair(3,COLOR_RED,COLOR_WHITE);
    }else{
        wprintw(win,"Does not have color!");
        endwin();
    }
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_WHITE);
    init_pair(2,COLOR_CYAN,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);

    PlateauScore plateau;
    plateau.plateau = plateauInitial();
    plateau.score = 0;
    wattron(win,COLOR_PAIR(1));
    mvwprintw(win,3,0,dessine(plateau.plateau).c_str());
    wattroff(win,COLOR_PAIR(1));
    wrefresh(win);
    wattron(win,COLOR_PAIR(3));
    mvwprintw(win,0,0,"Saisir q pour quitter");
    wattroff(win,COLOR_PAIR(3));
    wrefresh(win);
    bool terminate;
    terminate = true;
    while (not estTermine(plateau) and not estGagnant(plateau.plateau) and terminate ==true) {
        mvwprintw(win,14,0,"                ");
        int d;
        d = wgetch(win);
        mvwprintw(win,1,0,"use up down left and right to control:");
        wrefresh(win);
        if (d==KEY_LEFT){
                mvwprintw(win,1,0,"                                             ");
                wrefresh(win);
                plateau = deplacement(plateau, GAUCHE);
        }else if(d==KEY_RIGHT){
                mvwprintw(win,1,0,"                                             ");
                wrefresh(win);
                plateau = deplacement(plateau, DROITE);
        }else if(d==KEY_UP){
                mvwprintw(win,1,0,"                                             ");
                wrefresh(win);
                plateau = deplacement(plateau, HAUT);
        }else if(d==KEY_DOWN){
                mvwprintw(win,1,0,"                                             ");
                wrefresh(win);
                plateau = deplacement(plateau, BAS);
        }else if(d==KEY_q){

            break;
        }else{
                mvwprintw(win,1,0,"please type in only up, down, right and left!");
                wrefresh(win);      
        }
        wattron(win,COLOR_PAIR(1));
        mvwprintw(win,3,0,dessine(plateau.plateau).c_str());
        wattroff(win,COLOR_PAIR(1));
        wattron(win,COLOR_PAIR(3));
        mvwprintw(win,2,0,"score:");
        mvwprintw(win,2,8,"%d",plateau.score);
        wrefresh(win);
        wattroff(win,COLOR_PAIR(3));
        if (estTermine(plateau)) {
            mvwprintw(win,14,0,"Vous avez perdu.");
            wrefresh(win);
            sleep(3);
                       
            plateau.plateau = plateauInitial();
            plateau.score = 0;
            mvwprintw(win,2,8,"      ");
            
        }
        else if (estGagnant(plateau.plateau)) {
            mvwprintw(win,14,0,"Vous avez perdu.");
            wrefresh(win);
            sleep(3);

            plateau.plateau = plateauInitial();
            plateau.score = 0;
            mvwprintw(win,2,8,"      ");
            
        }
    }

    endwin();
}

