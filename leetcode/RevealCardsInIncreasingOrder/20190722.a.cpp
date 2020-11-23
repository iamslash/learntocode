/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>

//       17 13 11 2 3 5 7
// deck: 2 3 5 7 11 13 17
//         i
// rslt: 2 0 0 0 0 0 0
//           p

// O(NlgN) O(N)
class Solution {
 public:
  std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    int n = deck.size();
    std::sort(deck.begin(), deck.end());
    std::vector<int> rslt(n, 0);
    rslt[0] = deck[0];
    for (int i = 1; i < n; ++i) {
      int p = 0;
      for (int j = 0; j < 2; p %= n, j += (rslt[p] ? 0 : 1))
        ++p;
      rslt[p] = deck[i];
    }
    return rslt;
  }
};

int main() {
  return 0;
}
