#include "../src/board.h"
#include <cstddef>

using tictactoe::Board;

#define LEN(arr) sizeof(arr) / sizeof(*arr)

Board makeBoard(unsigned moves[], size_t len) {
  Board board;

  for (size_t i = 0; i < len; ++i) {
    board.doMove(moves[i]);
  }

  return board;
}
