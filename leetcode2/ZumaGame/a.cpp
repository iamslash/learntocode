/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

// 0ms 100.00% 6.1MB 78.57%
// back tracking
// O(B!) O(B)
class Solution {
 private:
  int minStep;
  void dfs(unordered_map<char, int>& cntMap, string& board, int used) {
    // base
    if (board.empty()) {
      minStep = min(minStep, used);
      return;
    }
    // recursion
    int i = 0;
    while (i < board.size()) {
      int j = i;
      char c = board[i];
      while (j < board.size() && board[j] == c)
        ++j;
      if (j - i < 3) {
        int miss = 3 - (j - i);
        if (cntMap[c] >= miss) {
          removeBoard(board, i, j);
          cntMap[c] -= miss;
          dfs(cntMap, board, used + miss);
          cntMap[c] += miss;
          restoreBoard(board, i, j-i, c);
        }
      } else {
        removeBoard(board, i, j);
        dfs(cntMap, board, used);
        restoreBoard(board, i, j-i, c);
      }
      i = j;
    }
  }
  void removeBoard(string& board, int beg, int end) {
    board.erase(board.begin() + beg, board.begin() + end);
  }
  void restoreBoard(string& board, int pos, int cnt, char c) {
    board.insert(pos, cnt, c);
  }
 public:
  int findMinStep(string board, string hand) {
    unordered_map<char, int> cntMap;
    for (char c : hand)
      cntMap[c]++;
    minStep = INT_MAX;
    dfs(cntMap, board, 0);
    if (minStep == INT_MAX)
      return -1;
    return minStep;
  }
};
