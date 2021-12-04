#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"modele.h"
using namespace std;

int juger(PlateauScore plateau){
    
}

int main(){
    ifstream configuration;
    configuration.open("configuration.txt");
    int k=0;
    PlateauScore plateau;
    plateau.plateau=plateauVide();
    plateau.score=0;
    string str;
    getline(configuration,str);
    k=str[0]-'0';
    plateau.score=str[2]-'0';
    int i=0;
    while(getline(configuration,str)and i<4){
        plateau.plateau[i][0]=str[0]-'0';
        plateau.plateau[i][1]=str[2]-'0';
        plateau.plateau[i][2]=str[4]-'0';
        plateau.plateau[i][3]=str[6]-'0';
        i++;
            
    }
    configuration.close();
    
    ofstream mouvements;
    mouvements.open("mouvements.txt");    
    mouvements<<"LGD"<<endl;
    string direction;
    while(true){
        if(k!=0 and k%6==0){
            ifstream configuration;
            configuration.open("configuration.txt");
            string str;
            getline(configuration,str);
            plateau.score=str[2]-'0';
            int i=0;
            while(getline(configuration,str)and i<4){
            plateau.plateau[i][0]=str[0]-'0';
            plateau.plateau[i][1]=str[2]-'0';
            plateau.plateau[i][2]=str[4]-'0';
            plateau.plateau[i][3]=str[6]-'0';
            i++;
            
            }
            configuration.close();
        }
        
        if(juger(plateau)==GAUCHE)
            direction="G";
        else if(juger(plateau)==DROITE)
            direction="D";
        else if(juger(plateau)==HAUT)
            direction="H";
        else if(juger(plateau)==BAS)
            direction="B";
        mouvements<<k<<direction<<endl;
        plateau=deplacement(plateau,juger(plateau));
        k++;
    }
}