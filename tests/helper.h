#include "../src/board.h"

using tictactoe::Board;

#define LEN(arr) sizeof(arr) / sizeof(*arr)

Board MakeBoard(unsigned moves[], size_t len) {
  Board board;

  for (size_t i = 0; i < len; ++i) {
    board.DoMove(moves[i]);
  }

  return board;
}
