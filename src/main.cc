#include "search.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

using tictactoe::Board;
using tictactoe::GameState;
using tictactoe::Player;
using tictactoe::search::search;

ostream &operator<<(ostream &o, Board const &board) {
  for (unsigned square = 0; square < 9; ++square) {
    if (board.isOccupiedBy(square, Player::Human)) {
      o << 'O';
    } else if (board.isOccupiedBy(square, Player::Comp)) {
      o << 'X';
    } else {
      o << '-';
    }

    if ((square + 1) % 3 == 0) {
      o << "\n";
    }
  }

  return o;
}

int main() {
  cout << "Tic-tac-toe. Choose a number from 1 to 9 to make a move.\n\n";

  Board board;
  cout << board << endl;

  while (!board.isGameOver()) {
    int square;
    cin >> square;

    if (square < 1 || square > 9) {
      cout << "\nChoose a number from 1 to 9.\n\n";
      continue;
    }

    if (board.isOccupied(square - 1)) {
      cout << "\nThat square is already taken!\n\n";
      continue;
    }

    board.doMove(square - 1);

    if (!board.isGameOver()) {
      int best_move = search(&board);
      board.doMove(best_move);
    }

    cout << endl << board << endl;
  }

  char const *game_state_str[] = {"You won!", "You lost!", "It's a draw!"};
  cout << game_state_str[board.gameState()] << endl;
}
