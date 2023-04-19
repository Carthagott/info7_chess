#include <iostream>
#include "board.hpp"
#include "types.hpp"

using namespace std;



char** Empty() {
    char** board = new char* [8];
    for (int i = 0; i < 8; i++)
    {
        board[i] = new char[8];
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = 'o';
        }
    }
    return board;
}


Piece get_square(char** board, Case case_tmp) {
    Piece* p = new Piece;
    p->empl.lig = case_tmp.lig;
    p->empl.col = case_tmp.col;
    p->type = board[case_tmp.lig][case_tmp.col];
    return *p;
}
void set_square(char **board, Case newEmpl, Piece p, Game* game) { 

    board[p.empl.lig][p.empl.col] = 'o';
        board[newEmpl.lig][newEmpl.col] = p.type;
        // sauvegarde de la nouvelle position de la piece
        p.empl.lig = newEmpl.lig;
        p.empl.col = newEmpl.col;
    }
void init_piece(Game* game, char liste_blanc[TAILLE_BOARD],char liste_noir[TAILLE_BOARD]) {

    for (int i = 0; i < TAILLE_BOARD; i++) {
        game->white_player[i].empl.lig = 1;
        game->white_player[i].empl.col = i;
        game->white_player[i].type = 'P';

        game->black_player[i].empl.lig =6 ;
        game->black_player[i].empl.col = i;
        game->black_player[i].type = 'p';
    }
    for (int j = 0; j < TAILLE_BOARD; j++) {
        game->white_player[j + TAILLE_BOARD].empl.lig = 0;
        game->white_player[j + TAILLE_BOARD].empl.col = j;

        game->white_player[j + 8].type = liste_blanc[j];
        game->black_player[j + TAILLE_BOARD].empl.lig = 7;
        game->black_player[j + TAILLE_BOARD].empl.col = j;

        game->black_player[j + 8].type = liste_noir[j];
    }
}
void start(char **board, Game game) {
    for (int i = 0; i < NB_PIECE; i++) {
        board[game.white_player[i].empl.lig][game.white_player[i].empl.col] =
            game.white_player[i].type;
        board[game.black_player[i].empl.lig][game.black_player[i].empl.col] =
            game.black_player[i].type;
    }
}
void changement_position_piece_player(Game* game, Case newEmpl, Piece p )
{
    int compteur=0;
    if (p.type > 'A')
    {
        for(int i=0;i<NB_PIECE;i++)
        {
            if ((game->white_player[i].empl.lig == p.empl.lig) && (game->white_player[i].empl.col == p.empl.col))
            {
                compteur = i;
                game->white_player[i].empl.lig = newEmpl.lig;
                game->white_player[i].empl.col = newEmpl.col;
            }
        
        } 

    }
    if (p.type < 'A')
    {
        for (int j = 0; j < NB_PIECE; j++)
        {
            if ((game->black_player[j].empl.lig == newEmpl.lig) && (game->black_player[j].empl.col == newEmpl.col))
            {
                game->black_player[j].empl.lig = newEmpl.lig; 
                game->black_player[j].empl.col = newEmpl.col;
            }
        }
     
    }
}
void move_piece(char** board, Game* game, Case oldEmpl, Case newEmpl)
{
    Piece p;

    p = get_square(board, oldEmpl);
    changement_position_piece_player(game, newEmpl, p);
    set_square(board, newEmpl, p,game);
    
}

string writeFen(char** board)
{
    string FEN; 
    int compteur = 48;
    char c;
    for (int i = 0; i < TAILLE_BOARD; i++)
    {
        for (int j = 0; j < TAILLE_BOARD; j++)
        {
            if (j == 7)
            {
                if (board[7 - i][7] == 'o')
                {
                    compteur = compteur + 1;
                    c = compteur;

                }
            }
          
        }
        FEN = FEN + '/';
    }
    return FEN;
}