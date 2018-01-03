#ifndef TICTACTOE_SEARCH_H
#define TICTACTOE_SEARCH_H

#include "board.h"

namespace tictactoe::search {

static const int kMaxEval = +10;

int Search(Board*, int = 0, int = -kMaxEval, int = +kMaxEval);

}; // namespace tictactoe::search

#endif
