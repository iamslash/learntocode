/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

// backtracking
// Time: O(4^N), Space: O(1)
// 36ms 57.09%
class Solution {
 private:
  bool dfs(std::vector<int>& S, std::vector<int>& V, int i, int t) {
    // base condition
    if (i == V.size()) {
      if (std::count(S.begin(), S.end(), S[0]) == 4)
        return true;
      return false;
    }

    // recursion
    for (int j = 0; j < 4; ++j) {
      if (S[j] + V[i] > t)
        continue;
      S[j] += V[i];
      if (dfs(S, V, i+1, t))
        return true;
      S[j] -= V[i];
    }

    return false;
  }
 public:
  bool makesquare(std::vector<int>& V) {
    if (V.size() < 4)
      return false;
    int sum = std::accumulate(V.begin(), V.end(), 0, std::plus<int>());
    if (sum % 4 != 0)
      return false;
    std::sort(V.begin(), V.end(), [](int a, int b) { return a > b; });
    std::vector<int> S(4, 0);
    return dfs(S, V, 0, sum/4);
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  // std::vector<int> V = {1, 1, 2, 2, 2};
  std::vector<int> V = {3, 3, 3, 3, 4};

  Solution sln;
  printb(sln.makesquare(V));
  
  return 0;
}
