#include <iostream>
#include "modele.h"
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
typedef vector<vector<int> > Plateau;


#define CHECK(test) if(!(test)) cout<< "Test failed in file "\
            <<__FILE__<<"line"<<__LINE__<<": " #test <<endl

void plateauVideTest(){
    Plateau t;
    t = Plateau(4);
    for(int i =0;i<4;i++){
        t[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t[i][j]=0;
        }
    }
    CHECK(plateauVide()==t);
}

void plateauInitialTest(){
    Plateau t;
    t = plateauInitial();
    int k =0;
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            if(t[i][j]==2 or t[i][j]==4){
                k++;
            }
        }
    }
    CHECK(k==2);
}

void tireDeuxOuQuatreTest(){
    CHECK(tireDeuxOuQuatre()==2 or tireDeuxOuQuatre()==4);
}

void deplacementGaucheTest(){
    // before the move
    PlateauScore t;
    t.plateau = Plateau(4);
    for(int i =0;i<4;i++){
        t.plateau[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t.plateau[i][j]=0;
        }
    }
    t.plateau[0][0]=4;
    t.plateau[0][1]=4;
    t.plateau[0][2]=2;
    t.plateau[0][3]=2;
    t.plateau[1][0]=4;
    t.score =0;

    //check if the vector is right
    CHECK(deplacementGauche(t).plateau[1][0]==4);
    CHECK(deplacementGauche(t).plateau[0][1]==4);
    CHECK(deplacementGauche(t).plateau[0][0]==8);
    //check if the score is added correctly
    CHECK(deplacementGauche(t).score==t.score+12);


}

void deplacementDroiteTest(){
    // before the move
    PlateauScore t;
    t.plateau = Plateau(4);
    for(int i =0;i<4;i++){
        t.plateau[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t.plateau[i][j]=0;
        }
    }
    t.plateau[0][1]=2;
    t.plateau[0][2]=8;
    t.plateau[0][3]=8;
    t.plateau[1][0]=4;
    t.score =0;

    //check if the vector is right
    CHECK(deplacementDroite(t).plateau[0][2]==2);
    CHECK(deplacementDroite(t).plateau[0][3]==16);
    CHECK(deplacementDroite(t).plateau[1][3]==4);
    //check if the score is added correctly
    CHECK(deplacementDroite(t).score==t.score+16);

}

void deplacementHautTest(){
    // before the move
    PlateauScore t;
    t.plateau = Plateau(4);
    for(int i =0;i<4;i++){
        t.plateau[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t.plateau[i][j]=0;
        }
    }
    t.plateau[0][0]=16;
    t.plateau[1][0]=16;
    t.plateau[2][1]=4;
    t.plateau[3][1]=4;
    t.plateau[2][2]=2;
    t.score =0;

    //check if the vector is right
    CHECK(deplacementHaut(t).plateau[0][0]==32);
    CHECK(deplacementHaut(t).plateau[0][1]==8);
    CHECK(deplacementHaut(t).plateau[0][2]==2);
    //check if the score is added correctly
    CHECK(deplacementHaut(t).score == t.score+40);

}

void deplacementBasTest(){
    // before the move
    PlateauScore t;
    t.plateau = Plateau(4);
    for(int i =0;i<4;i++){
        t.plateau[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t.plateau[i][j]=0;
        }
    }
    t.plateau[0][0]=2;
    t.plateau[0][1]=4;
    t.plateau[1][1]=4;
    t.plateau[0][3]=16;
    t.plateau[3][3]=16;
    t.score =0;

    //check if the vector is right
    CHECK(deplacementBas(t).plateau[3][0]==2);
    CHECK(deplacementBas(t).plateau[3][1]==8);
    CHECK(deplacementBas(t).plateau[3][3]==32);
    //check if the score is added correctly
    CHECK(deplacementBas(t).score == t.score+40);

}


void dessineTest(){
    Plateau t;
    t = Plateau(4);
    for(int i =0;i<4;i++){
        t[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t[i][j]=0;
        }
    }
    t[0][0]=2;
    t[0][1]=4;
    t[1][1]=4;
    t[0][3]=16;
    t[3][3]=16;
    stringstream m_test;
    string s_test;
    m_test << "*************************" << endl;
    m_test << "*"<<"  "<<2<<"  "<<"*"<<"  "<<4<<"  "<<"*"<<"     "<<"*"<<" "<<16<<"  *"<<endl;
    m_test << "*************************" << endl;
    m_test << "*     *"<<"  "<<4<<"  *"<<"     *     *" <<endl;
    m_test << "*************************" << endl;
    m_test << "*     *     *     *     *" <<endl;
    m_test << "*************************" << endl;
    m_test << "*     *     *     *"<<" "<<16<<"  *" <<endl;
    m_test << "*************************" << endl;
    s_test = m_test.str();
    CHECK( dessine(t) == s_test);
}


void estTermineTest(){
    PlateauScore t;
    t.plateau = Plateau(4);
    for(int i =0;i<4;i++){
        t.plateau[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t.plateau[i][j]=0;
        }
    }
    t.plateau[0][0]=2;
    t.plateau[0][1]=4;
    t.plateau[1][1]=4;
    t.plateau[0][3]=16;
    t.plateau[3][3]=16;


    PlateauScore plateau;
    plateau.plateau = Plateau(4);
    for(int i =0;i<4;i++){
        plateau.plateau[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            plateau.plateau[i][j]=0;
        }
    }
    plateau.plateau[0][0]=2;
    plateau.plateau[0][1]=32;
    plateau.plateau[0][2]=16;
    plateau.plateau[0][3]=8;
    plateau.plateau[1][0]=16;
    plateau.plateau[1][1]=2;
    plateau.plateau[1][2]=8;
    plateau.plateau[1][3]=4;
    plateau.plateau[2][0]=8;
    plateau.plateau[2][1]=4;
    plateau.plateau[2][2]=2;
    plateau.plateau[2][3]=16;
    plateau.plateau[3][0]=4;
    plateau.plateau[3][1]=8;
    plateau.plateau[3][2]=4;
    plateau.plateau[3][3]=2;


    CHECK(estTermine(t)==false);
    CHECK(estTermine(plateau)==true);

}



void estGagnantTest(){
    Plateau t;
    t = Plateau(4);
    for(int i =0;i<4;i++){
        t[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t[i][j]=0;
        }
    }
    t[0][0]=2;
    t[0][1]=4;
    t[1][1]=4;
    t[0][3]=16;
    t[3][3]=16;

    Plateau t1;
    t1 = Plateau(4);
    for(int i =0;i<4;i++){
        t1[i] = vector<int>(4);
        for(int j = 0;j <4;j++){
            t1[i][j]=0;
        }
    }
    t1[0][0]=2;
    t1[0][1]=4;
    t1[1][1]=4;
    t1[0][3]=16;
    t1[3][3]=2048;


    CHECK(estGagnant(t)==false);
    CHECK(estGagnant(t1)==true);
}

int main(){
   
    plateauVideTest();
    plateauInitialTest();
    deplacementGaucheTest();
    deplacementHautTest();
    deplacementDroiteTest();
    deplacementBasTest();
    dessineTest();
    estTermineTest();
    return 0;
}


