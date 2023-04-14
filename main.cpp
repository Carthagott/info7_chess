#include <iostream>
#include "board.hpp"
#include "types.hpp"


using namespace std;

const int TAILLE_BOARD = 8;
const int NB_PIECE = 16;

int main(void){

  Game game;

  char white_player[TAILLE_BOARD] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
  char black_player[TAILLE_BOARD] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};

  char board[TAILLE_BOARD][TAILLE_BOARD]; // declaration de l'echiquier
  empty(board);
  afficherPlateau(board);
  init_piece(&game, white_player, black_player);
  start(board, game);
  cout << endl;
  afficherPlateau(board);

  return 0;
}