#include "../src/board.h"
#include "helper.h"
#include "gtest/gtest.h"

using tictactoe::Board;
using tictactoe::GameState;
using tictactoe::Player;

TEST(BoardTest, DoMove) {
  Board board;
  unsigned sq = 4;

  board.doMove(sq);

  EXPECT_TRUE(board.isComputerMove());
  EXPECT_TRUE(board.isOccupied(sq));
  EXPECT_EQ(board.occupancy(), 1);
}

TEST(BoardTest, UndoMove) {
  Board board;
  unsigned sq = 4;

  board.doMove(sq);
  board.undoMove(sq);

  EXPECT_FALSE(board.isComputerMove());
  EXPECT_FALSE(board.isOccupied(sq));
  EXPECT_EQ(board.occupancy(), 0);
}

TEST(BoardTest, DetectWinForComp) {
  // xox
  // oxo
  // -ox
  unsigned moves[] = {1, 0, 3, 2, 5, 4, 7, 8};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.isGameOver());
  EXPECT_EQ(board.gameState(), GameState::WinComp);
}

TEST(BoardTest, DetectWinForHuman) {
  // oxo
  // xox
  // o--
  unsigned moves[] = {0, 1, 2, 3, 4, 5, 6};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.isGameOver());
  EXPECT_EQ(board.gameState(), GameState::WinHuman);
}

TEST(BoardTest, DetectDraw) {
  // xox
  // oxo
  // oxo
  unsigned moves[] = {1, 0, 3, 2, 5, 4, 6, 7, 8};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.isGameOver());
  EXPECT_EQ(board.gameState(), GameState::Draw);
}
