#ifndef SRC_SEARCH_H_
#define SRC_SEARCH_H_

#include "board.h"

namespace tictactoe::search {

static const int MaxEval = 10;

int search(Board *, int = 0, int = -MaxEval, int = MaxEval);

} // namespace tictactoe::search

#endif // SRC_SEARCH_H_
