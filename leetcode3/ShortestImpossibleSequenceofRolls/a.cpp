/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

// 267ms 80.89% 108.5MB 52.47%
// hash set
// O(N) O(K)
class Solution {
public:
  int shortestSequence(vector<int>& rolls, int k) {
    int ans = 1;
    unordered_set<int> diceSet;
    for (int& roll : rolls) {
      diceSet.insert(roll);
      if (diceSet.size() == k) {
        diceSet.clear();
        ans++;
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
