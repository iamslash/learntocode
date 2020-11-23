/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <deque>

// 8ms 98.87% 9.3MB 36.00%
// deque
// O(NlgN) O(N)
class Solution {
 public:
  std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    std::sort(deck.rbegin(), deck.rend());
    std::deque<int> deq;
    int n = deck.size();
    deq.push_back(deck[0]);
    for (int i = 1; i < n; ++i) {
      deq.push_front(deq.back()); deq.pop_back();
      deq.push_front(deck[i]);
    }
    return std::vector<int>(deq.begin(), deq.end());
  }
};

int main() {
  return 0;
}
