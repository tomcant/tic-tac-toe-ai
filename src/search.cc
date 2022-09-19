#include "search.h"

namespace tictactoe::search {

namespace {

int GameOverScore(Board *board) {
  return board->DetermineGameState() == kDraw ? 0 : board->Occupancy() - kMaxEval;
}

}  // anonymous namespace

int Search(Board *board, int depth, int alpha, int beta) {
  if (board->IsGameOver()) {
    return GameOverScore(board);
  }

  int best_move = -1;

  for (unsigned square = 0; square < 9; ++square) {
    if (board->IsOccupied(square)) {
      continue;
    }

    board->DoMove(square);
    int eval = -Search(board, depth + 1, -beta, -alpha);
    board->UndoMove(square);

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

}  // namespace tictactoe::search
