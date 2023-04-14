#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include "types.hpp"

using namespace std;


//Creation plateau vide
void empty(char);

//Recuperer le contenu d'une case
Piece get_square(char, Case);

//Afficher plateau
void afficherPlateau(char);

//Modifier le contenu d'une case
void set_square(char, Case, Piece);

//Initialiser le plateau avec ses pieces
void init_piece(Game, char, char);
void start(char, Game);

//Deplacer une piece d'une case de depart dans une case d'arrivee
void move_piece(char, Game, Case, Case);

#endif