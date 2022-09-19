#include "board.h"
#include <cstddef>

namespace tictactoe {

bool Board::isOccupied(unsigned square) const {
  return (grid[Human] | grid[Comp]) & 1 << square;
}

bool Board::isOccupiedBy(unsigned square, Player player) const {
  return grid[player] & 1 << square;
}

unsigned Board::occupancy() const {
  unsigned occupancy = 0;

  for (unsigned square = 0; square < 9; ++square) {
    isOccupied(square) && ++occupancy;
  }

  return occupancy;
}

GameState Board::gameState() const {
  static const int wins[] = {0x007, 0x038, 0x1C0, 0x049,
                             0x092, 0x124, 0x111, 0x054};

  for (size_t i = 0; i < 8; ++i) {
    if ((grid[Human] & wins[i]) == wins[i]) {
      return WinHuman;
    }

    if ((grid[Comp] & wins[i]) == wins[i]) {
      return WinComp;
    }
  }

  return occupancy() == 9 ? Draw : Playing;
}

void Board::doMove(unsigned square) {
  grid[player_to_move] |= 1 << square;
  togglePlayerToMove();
}

void Board::undoMove(unsigned square) {
  togglePlayerToMove();
  grid[player_to_move] ^= 1 << square;
}

} // namespace tictactoe
