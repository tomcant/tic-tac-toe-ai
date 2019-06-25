#ifndef SRC_SEARCH_H_
#define SRC_SEARCH_H_

#include "board.h"

namespace tictactoe::search {

static const int kMaxEval = +10;

int Search(Board*, int = 0, int = -kMaxEval, int = +kMaxEval);

}  // namespace tictactoe::search

#endif  // SRC_SEARCH_H_
