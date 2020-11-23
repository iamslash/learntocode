/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <map>
#include <set>

// 16ms 72.13% 12.7MB 100.00%
// reverse index
// addScore: O(lgN) O(N)
//      top: O(N)   O(N)
//    reset: O(lgN) O(N)
class Leaderboard {
 public:
  std::map<int, int> M; // {id, score}
  std::set<std::pair<int, int>> S; // {score, id}
  Leaderboard() {
  }
  void addScore(int id, int score) {
    S.erase({M[id], id});
    M[id] += score;
    S.insert({M[id], id});
  }
  int top(int K) {
    int sum = 0;
    int cnt = 0;
    for (auto it = S.rbegin(); it != S.rend() && cnt < K; it++) {
      sum += it->first;
      cnt++;
    }
    return sum;
  }
  void reset(int id) {
    S.erase({M[id], id});
    M[id] = 0;
  }
};

int main() {
  return 0;
}
