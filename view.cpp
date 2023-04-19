#include <iostream>
#include "board.hpp"
#include "types.hpp"
using namespace std;

void print_board(char** board) {
    for (int i = 0; i < TAILLE_BOARD; i++) {
        for (int j = 0; j < TAILLE_BOARD; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
void print_square(char** board, Case Empl)
{
    cout << board[Empl.lig][Empl.col];
}