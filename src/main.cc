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

/*
 * Define what it means to write a Tic-tac-toe board to an output stream.
 */
ostream& operator<<(ostream &o, Board const &board) {
  for (unsigned square = 0; square < 9; ++square) {
    if (board.IsOccupiedBy(square, Player::kHuman)) {
      o << 'o';
    } else if (board.IsOccupiedBy(square, Player::kComp)) {
      o << 'x';
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
  cout << "Tic-tac-toe. Use the numbers from 1 to 9 to make a move.\n\n";

  Board board;
  cout << board << endl;

  GameState state;

  do {
    int square;
    cin >> square;
    board.DoMove(square - 1);

    int best_move = Search(&board);
    board.DoMove(best_move);

    cout << endl << board << endl;

    state = board.DetermineGameState();
  } while (state == GameState::kPlaying);

  char const *game_state_str[] = {
    "You won!", "You lost!", "It's a draw!"
  };

  cout << game_state_str[state] << endl;
}
