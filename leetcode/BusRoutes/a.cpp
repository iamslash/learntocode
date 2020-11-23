/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// 196ms 74.62% 53.6MB 27.63%
// O(N) O(N)
class Solution {
 public:
  int numBusesToDestination(
      std::vector<std::vector<int>>& R, int S, int T) {
    std::unordered_map<int, std::unordered_set<int>> stop2bus;
    for (int i = 0; i < R.size(); ++i) {
      for (int stop : R[i]) {
        stop2bus[stop].insert(i);
      }
    }
    std::queue<std::pair<int, int>> q;
    q.push({S, 0});
    std::unordered_set<int> seen = {S};
    while (!q.empty()) {
      auto pr = q.front(); q.pop();
      int u = pr.first;
      int cnt  = pr.second;
      if (u == T)
        return cnt;
      for (auto& bus : stop2bus[u]) {
        for (auto& v : R[bus]) {
          if (seen.count(v) == 0) {
            seen.insert(v);
            q.push({v, cnt+1});
          }
        }
        R[bus].clear();
      }
    }
    return -1;
  }
};

int main() {

  std::vector<std::vector<int>> R =  {{1, 2, 7}, {3, 6, 7}};
  int S = 1;
  int T = 6;
  // std::vector<std::vector<int>> R =  {{2}, {2, 8}};
  // int S = 8;
  // int T = 2;

  Solution sln;
  printf("%d\n", sln.numBusesToDestination(R, S, T));
  
  return 0;
}
