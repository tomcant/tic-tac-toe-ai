#include "search.h"

namespace tictactoe::search {

namespace {

int Evaluate(Board const &board) {
  GameState state = board.DetermineGameState();

  if (state == kWinHuman || state == kWinComp) {
    int eval = kMaxEval - board.DetermineOccupancy();
    int multiplier = state == kWinHuman ? 1 : -1;

    if (board.IsComputerMove()) {
      multiplier *= -1;
    }

    return eval * multiplier;
  }

  if (state == kDraw) {
    return 0;
  }
}

} // anonymous namespace

int Search(Board *board, int depth, int alpha, int beta) {
  if (board->DetermineGameState() != kPlaying) {
    return Evaluate(*board);
  }

  int best_move = -1;

  for (unsigned square = 0; square < 9; ++square) {
    if (board->IsOccupied(square)) {
      continue;
    }

    board->DoMove(square);
    int evaluation = -Search(board, depth + 1, -beta, -alpha);
    board->UndoMove(square);

    if (alpha < evaluation) {
      alpha = evaluation;
      best_move = square;

      if (alpha >= beta) {
        break;
      }
    }
  }

  return depth > 0 ? alpha : best_move;
}

} // namespace tictactoe::search
