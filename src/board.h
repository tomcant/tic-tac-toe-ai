#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_

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
  unsigned Occupancy() const;
  GameState DetermineGameState() const;

  void DoMove(unsigned);
  void UndoMove(unsigned);

  inline bool IsGameOver() const {
    return DetermineGameState() != kPlaying;
  }

  inline Player player_to_move() const {
    return player_to_move_;
  }

 private:
  unsigned grid_[2];
  Player player_to_move_;

  void TogglePlayerToMove();
};

}  // namespace tictactoe

#endif  // SRC_BOARD_H_
