#include "gtest/gtest.h"
#include "helper.h"
#include "../src/search.h"

using tictactoe::Board;
using tictactoe::search::Search;

TEST(SearchTest, FindWinningMove) {
  // o--
  // xx-
  // oo-
  unsigned moves[] = { 0, 3, 6, 4, 7 };
  Board board = MakeBoard(moves, 5);

  EXPECT_EQ(Search(&board), 5);
}

TEST(SearchTest, AvoidLosing) {
  // --o
  // -o-
  // --x
  unsigned moves[] = { 2, 8, 4 };
  Board board = MakeBoard(moves, 3);

  EXPECT_EQ(Search(&board), 6);
}
