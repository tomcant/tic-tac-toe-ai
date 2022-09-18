#include "gtest/gtest.h"
#include "helper.h"
#include "../src/board.h"

using tictactoe::Board;
using tictactoe::GameState;
using tictactoe::Player;

TEST(BoardTest, DoMove) {
  Board board;
  unsigned sq = 4;

  board.DoMove(sq);

  EXPECT_TRUE(board.IsComputerMove());
  EXPECT_TRUE(board.IsOccupied(sq));
  EXPECT_EQ(board.Occupancy(), 1);
}

TEST(BoardTest, UndoMove) {
  Board board;
  unsigned sq = 4;

  board.DoMove(sq);
  board.UndoMove(sq);

  EXPECT_FALSE(board.IsComputerMove());
  EXPECT_FALSE(board.IsOccupied(sq));
  EXPECT_EQ(board.Occupancy(), 0);
}

TEST(BoardTest, DetectWin) {
  // oxo
  // xox
  // o--
  unsigned moves[] = { 0, 1, 2, 3, 4, 5, 6 };
  Board board = MakeBoard(moves, 7);

  EXPECT_TRUE(board.IsGameOver());
  EXPECT_EQ(board.DetermineGameState(), GameState::kWinHuman);
}

TEST(BoardTest, DetectDraw) {
  // xox
  // oxo
  // oxo
  unsigned moves[] = { 1, 0, 3, 2, 5, 4, 6, 7, 8 };
  Board board = MakeBoard(moves, 9);

  EXPECT_TRUE(board.IsGameOver());
  EXPECT_EQ(board.DetermineGameState(), GameState::kDraw);
}
