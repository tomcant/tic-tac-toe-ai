#ifndef TICTACTOE_BOARD_H_
#define TICTACTOE_BOARD_H_

namespace tictactoe {

enum GameState {
  kWinHuman,
  kWinComp,
  kDraw,
  kPlaying
};

enum Player {
  kHuman,
  kComp
};

class Board {
 public:
  Board() : grid_{}, player_to_move_(kHuman) {}

  bool IsComputerMove() const;
  bool IsOccupied(unsigned) const;
  bool IsOccupiedBy(unsigned, Player) const;
  unsigned DetermineOccupancy() const;
  GameState DetermineGameState() const;

  void DoMove(unsigned);
  void UndoMove(unsigned);
  void TogglePlayerToMove();

  inline Player player_to_move() const {
    return player_to_move_;
  }

 private:
  unsigned grid_[2];
  Player player_to_move_;
};

} // namespace tictactoe

#endif
