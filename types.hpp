#ifndef TYPES_HPP
#define TYPES_HPP
#include <iostream>
#include "board.hpp"
const int NB_PIECE = 16;
const int TAILLE_BOARD = 8;

using namespace std;


struct Case {
	int lig{};
	int col{};
};

struct Piece {
	Case empl{};
	bool est_prise{};
	char type{};
};

// contiendra tous les objets qui permettent de décrire le statut du jeu à chaque instant
struct Game {
	Piece white_player[NB_PIECE] ;

	Piece black_player[NB_PIECE] ;
};

#endif