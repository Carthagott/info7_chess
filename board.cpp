#include <iostream>
#include "board.hpp"
#include "types.hpp"

using namespace std;

const int TAILLE_BOARD = 8;
const int NB_PIECE = 16;

void empty(char board[TAILLE_BOARD][TAILLE_BOARD]) {
  for (int i = 0; i < TAILLE_BOARD; i++) {
    for (int j = 0; j < TAILLE_BOARD; j++) {
      board[i][j] = 'o';
    }
  }
}

Piece get_square(char board[TAILLE_BOARD][TAILLE_BOARD], Case case_tmp) {
  Piece *p = new Piece;
  p->empl->lig = case_tmp.lig;
  p->empl->col = case_tmp.col;
  p->type = board[case_tmp.lig][case_tmp.col];
  return *p;
}

void afficherPlateau(char board[TAILLE_BOARD][TAILLE_BOARD]) {
  for (int i = 0; i < TAILLE_BOARD; i++) {
    for (int j = 0; j < TAILLE_BOARD; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
}

/**
 * @brief Permet de placer ou enlever une piece
 * @param p : La nouvelle pièce à placer sur la case
 * @param newEmpl : La case à modifier
 */
void set_square(char board[TAILLE_BOARD][TAILLE_BOARD], Case newEmpl, Piece p) {
  // Verifier si on est pas hors jeu
  while (!((newEmpl.lig >= 0 && newEmpl.lig <= 7) &&
           (newEmpl.col >= 0 && newEmpl.col <= 7))) {
    cout << "Erreur d'emplacement, saisir ligne : " << endl;
    cin >> newEmpl.lig;
    cout << "Saisir colonne : " << endl;
    cin >> newEmpl.col;
  }
  if (board[newEmpl.lig][newEmpl.col] == 'o') {
    board[newEmpl.lig][newEmpl.col] = p.type;

    // sauvegarde de la nouvelle position de la piece
    p.empl->lig = newEmpl.lig;
    p.empl->col = newEmpl.col;
  }
  // Autres idées :
  /**
   * 1- Verifier si le mouvement est possible
   * 2- Si une piece est prise -> la retirer du plateau
   */
}

void init_piece(Game *game, char liste_blanc[TAILLE_BOARD],
                char liste_noir[TAILLE_BOARD]) {

  for (int i = 0; i < TAILLE_BOARD; i++) {
    game->white_player[i].empl = new Case{1, i};
    game->white_player[i].type = 'P';

    game->black_player[i].empl = new Case{6, i};
    game->black_player[i].type = 'p';
  }
  for (int j = 0; j < TAILLE_BOARD; j++) {
    game->white_player[j + TAILLE_BOARD].empl = new Case{0, j};
    game->white_player[j + 8].type = liste_blanc[j];
    game->black_player[j + TAILLE_BOARD].empl = new Case{7, j};
    game->black_player[j + 8].type = liste_noir[j];
  }
}

// Initialisation du plateau avec ses pièces
void start(char board[TAILLE_BOARD][TAILLE_BOARD], Game game) {
  for (int i = 0; i < NB_PIECE; i++) {
    board[game.white_player[i].empl->lig][game.white_player[i].empl->col] =
        game.white_player[i].type;
    board[game.black_player[i].empl->lig][game.black_player[i].empl->col] =
        game.black_player[i].type;
  }
}

void move_piece(char board[TAILLE_BOARD][TAILLE_BOARD],Game game, Case oldEmpl, Case newEmpl)
{   
    Piece p;
    p = get_square(board,oldEmpl);
    set_square(board,newEmpl,p);
}