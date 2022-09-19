#include "search.h"

namespace tictactoe::search {

int search(Board *board, int depth, int alpha, int beta) {
  if (board->isGameOver()) {
    return board->gameState() == Draw ? 0 : board->occupancy() - MaxEval;
  }

  int best_move = -1;

  for (unsigned square = 0; square < 9; ++square) {
    if (board->isOccupied(square)) {
      continue;
    }

    board->doMove(square);
    int eval = -search(board, depth + 1, -beta, -alpha);
    board->undoMove(square);

    if (eval >= beta) {
      return beta;
    }

    if (eval > alpha) {
      alpha = eval;
      best_move = square;
    }
  }

  return depth > 0 ? alpha : best_move;
}

} // namespace tictactoe::search
