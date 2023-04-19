
#include <iostream>
#include "board.hpp"
#include "types.hpp"
#include "view.hpp"

using namespace std;

int main(void) {

	Game game;
	Case oldEmpl, newEmpl, oldwhite, oldblack, NewWhite, NewBlack;
	oldEmpl = { 0, 0};
	newEmpl = { 4,3 };
	oldblack = { 7,0 };
	oldwhite = { 0,7 };
	NewWhite = { 4,1 };
	NewBlack = { 4,2 };
	string FEN;
	char white_player[TAILLE_BOARD] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
	char black_player[TAILLE_BOARD] = { 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' };

	char** board; // declaration de l'echiquier
	board=Empty();
	init_piece(&game, white_player, black_player);
	start(board, game);
	cout << endl;
	cout << endl;
	move_piece(board, &game, oldEmpl, newEmpl);
	move_piece(board, &game, oldwhite, NewWhite);
	move_piece(board, &game, oldblack, NewBlack);
	print_board(board);
	FEN = writeFen(board);
	cout << FEN;

	return 0;
}

