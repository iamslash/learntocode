/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 8ms 87.76% 7.8MB 49.19%
// dynamic programming
// O(N) O(N)
class Solution {
 private:
  int dist(char a, char b) {
    if (a == 26)
      return 0;
    return abs(a/6 - b/6) + abs(a%6-b%6);
  }
  int dfs(vector<vector<int>>& C,
          string& s, int i, int other) {
    // base
    if (i == s.size())
      return 0;
    // memo
    int& r = C[i][other];
    if (r >= 0)
      return r;
    // recursion
    int dest = s[i] - 'A';
    int last = s[i-1] - 'A';
    r = min(dist(last, dest) + dfs(C, s, i+1, other),
            dist(other, dest) + dfs(C, s, i+1, last));
    return r;
  }
 public:
  int minimumDistance(string s) {
    int n = s.size();
    vector<vector<int>> C(n, vector<int>(27, -1));
    return dfs(C, s, 1, 26);
  }
};

int main() {
  return 0;
}
