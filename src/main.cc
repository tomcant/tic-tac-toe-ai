#include <iostream>
#include "search.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

using tictactoe::Board;
using tictactoe::GameState;
using tictactoe::Player;
using tictactoe::search::Search;

ostream& operator<<(ostream &o, Board const &board) {
  for (unsigned square = 0; square < 9; ++square) {
    if (board.IsOccupiedBy(square, Player::kHuman)) {
      o << 'O';
    } else if (board.IsOccupiedBy(square, Player::kComp)) {
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

  while (!board.IsGameOver()) {
    int square;
    cin >> square;

    if (square < 1 || square > 9) {
      cout << "\nChoose a number from 1 to 9.\n\n";
      continue;
    }

    if (board.IsOccupied(square - 1)) {
      cout << "\nThat square is already taken!\n\n";
      continue;
    }

    board.DoMove(square - 1);

    if (!board.IsGameOver()) {
      int best_move = Search(&board);
      board.DoMove(best_move);
    }

    cout << endl << board << endl;
  }

  char const *game_state_str[] = {
    "You won!", "You lost!", "It's a draw!"
  };

  cout << game_state_str[board.DetermineGameState()] << endl;
}
