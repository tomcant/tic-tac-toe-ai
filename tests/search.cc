#include "../src/search.h"
#include "helper.h"
#include "gtest/gtest.h"

using tictactoe::Board;
using tictactoe::search::search;

TEST(SearchTest, FindWinningMoveForComp) {
  // o--
  // xx-
  // oo-
  unsigned moves[] = {0, 3, 6, 4, 7};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.isComputerMove());
  EXPECT_EQ(search(&board), 5);
}

TEST(SearchTest, FindWinningMoveForHuman) {
  // ---
  // xx-
  // oo-
  unsigned moves[] = {6, 3, 7, 4};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_FALSE(board.isComputerMove());
  EXPECT_EQ(search(&board), 8);
}

TEST(SearchTest, AvoidLossForComp) {
  // --o
  // -o-
  // --x
  unsigned moves[] = {2, 8, 4};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.isComputerMove());
  EXPECT_EQ(search(&board), 6);
}

TEST(SearchTest, AvoidLossForHuman) {
  // -ox
  // -x-
  // --o
  unsigned moves[] = {8, 2, 1, 4};
  Board board = makeBoard(moves, LEN(moves));

  EXPECT_FALSE(board.isComputerMove());
  EXPECT_EQ(search(&board), 6);
}
