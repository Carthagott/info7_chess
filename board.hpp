#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "types.hpp"
#include "view.hpp"

using namespace std;


//Creation plateau vide
char** Empty();

//Recuperer le contenu d'une case
Piece get_square(char**, Case);



//Modifier le contenu d'une case
void set_square(char**, Case, Piece);

//Initialiser le plateau avec ses pieces
void init_piece(Game*, char[TAILLE_BOARD], char[TAILLE_BOARD]);
void start(char**, Game);
int trouve_la_piece_joueur(Game*, Piece,Case);
//Deplacer une piece d'une case de depart dans une case d'arrivee
void move_piece(char**, Game*, Case, Case);
//Afficher plateau
void changement_position_piece_player(Game*, Case,Case);
string writeFen(char**);
#endif