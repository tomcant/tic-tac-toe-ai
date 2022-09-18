#include "../src/board.h"

using tictactoe::Board;

Board MakeBoard(unsigned moves[], size_t len) {
  Board board;

  for (unsigned i = 0; i < len; ++i) {
    board.DoMove(moves[i]);
  }

  return board;
}
