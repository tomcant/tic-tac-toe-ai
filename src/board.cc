#include "board.h"

namespace tictactoe {

bool Board::IsComputerMove() const {
  return player_to_move() == kComp;
}

bool Board::IsOccupied(unsigned square) const {
  return (grid_[kHuman] | grid_[kComp]) & 1 << square;
}

bool Board::IsOccupiedBy(unsigned square, Player player) const {
  return grid_[player] & 1 << square;
}

unsigned Board::DetermineOccupancy() const {
  unsigned occupancy = 0;

  for (unsigned square = 0; square < 9; ++square) {
    IsOccupied(square) && ++occupancy;
  }

  return occupancy;
}

GameState Board::DetermineGameState() const {
  // There are 8 winning combinations on the 3x3 grid.
  static const int wins[] = {
    0x007, 0x038, 0x1C0, 0x049,
    0x092, 0x124, 0x111, 0x054
  };

  for (unsigned i = 0; i < 8; ++i) {
    if ((grid_[kHuman] & wins[i]) == wins[i]) {
      return kWinHuman;
    }

    if ((grid_[kComp] & wins[i]) == wins[i]) {
      return kWinComp;
    }
  }

  // If there is no win and the board is full then the game is drawn.
  if ((grid_[kHuman] | grid_[kComp]) == 0x1FF) {
    return kDraw;
  }

  return kPlaying;
}

void Board::DoMove(unsigned square) {
  grid_[player_to_move()] |= 1 << square;
  TogglePlayerToMove();
}

void Board::UndoMove(unsigned square) {
  TogglePlayerToMove();
  grid_[player_to_move()] ^= 1 << square;
}

void Board::TogglePlayerToMove() {
  player_to_move_ = IsComputerMove() ? kHuman : kComp;
}

} // namespace tictactoe
