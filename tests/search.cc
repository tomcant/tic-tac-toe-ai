#include "gtest/gtest.h"
#include "helper.h"
#include "../src/search.h"

using tictactoe::Board;
using tictactoe::search::Search;

TEST(SearchTest, FindWinningMoveForComp) {
  // o--
  // xx-
  // oo-
  unsigned moves[] = { 0, 3, 6, 4, 7 };
  Board board = MakeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.IsComputerMove());
  EXPECT_EQ(Search(&board), 5);
}

TEST(SearchTest, FindWinningMoveForHuman) {
  // ---
  // xx-
  // oo-
  unsigned moves[] = { 6, 3, 7, 4 };
  Board board = MakeBoard(moves, LEN(moves));

  EXPECT_FALSE(board.IsComputerMove());
  EXPECT_EQ(Search(&board), 8);
}

TEST(SearchTest, AvoidLossForComp) {
  // --o
  // -o-
  // --x
  unsigned moves[] = { 2, 8, 4 };
  Board board = MakeBoard(moves, LEN(moves));

  EXPECT_TRUE(board.IsComputerMove());
  EXPECT_EQ(Search(&board), 6);
}

TEST(SearchTest, AvoidLossForHuman) {
  // -ox
  // -x-
  // --o
  unsigned moves[] = { 8, 2, 1, 4 };
  Board board = MakeBoard(moves, LEN(moves));

  EXPECT_FALSE(board.IsComputerMove());
  EXPECT_EQ(Search(&board), 6);
}
