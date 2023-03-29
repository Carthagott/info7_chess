#include <iostream>
using namespace std;
const int huit=8;
const int seize=16;
struct piece
{
    int lig;
    int col;
    int indice; //vaut pour le numéro de piece dans la liste du joueur
    int id;  //id vaut pour le type de piece ( tour/reine/roi )
    string couleur;

};

void empty(int tab[huit][huit])
{
     for (int i=0;i<huit;i++)
    {
        for(int j=0;j<huit;j++)
        {
            tab[i][j]=0;
        }

    }

}

void start(int tab[huit][huit], piece joueur1[seize],piece joueur2[seize])
 //on place les pièces sur l'échiquier
{
    for(int i=0;i<seize;i++)
    {
        tab[joueur1[i].lig][joueur1[i].col]=joueur1[i].id;
        tab[joueur2[i].lig][joueur2[i].col]=joueur2[i].id;

    }
}



int main()
 {
     return 0;
 }
