#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_

namespace tictactoe {

enum Player { Human, Comp };
enum GameState { WinHuman, WinComp, Draw, Playing };

class Board {
public:
  Board() : grid{0, 0}, player_to_move(Human) {}

  bool isOccupied(unsigned) const;
  bool isOccupiedBy(unsigned, Player) const;
  unsigned occupancy() const;
  GameState gameState() const;

  void doMove(unsigned);
  void undoMove(unsigned);

  inline bool isComputerMove() const { return player_to_move == Comp; }
  inline bool isGameOver() const { return gameState() != Playing; }

private:
  unsigned grid[2];
  Player player_to_move;

  inline void togglePlayerToMove() {
    player_to_move = isComputerMove() ? Human : Comp;
  }
};

} // namespace tictactoe

#endif // SRC_BOARD_H_
