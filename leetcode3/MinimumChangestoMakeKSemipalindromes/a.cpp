/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 72ms 99.15% 6.9MB 93.72%
// recursive dynamic programming
// O(N^3) (N)
// difficult
class Solution {
private:
  // [index of s][group count] = minimum ops
  int finalMinOps[201][101] = {};
  // [index of s][length of substring] = minimum ops
  int semiMinOps[201][201];
  int divMinOps[201][201];
  
  int dfs(const string& s, int k, int i) {
    int n = s.size();
    const int MAX_CNT = 10000;
    // base
    if (i == n && k == 0) {
      return 0;
    }
    if (i >= n || k <= 0) {
      return MAX_CNT;
    }
    // memo
    if (finalMinOps[i][k] > 0) {
      return finalMinOps[i][k] - 1;
    }
    // recursion
    finalMinOps[i][k] = MAX_CNT;
    for (int len = 2; i + len <= n; ++len) {
      finalMinOps[i][k] = min(finalMinOps[i][k],
                              1 + semiMinOps[i][len] + dfs(s, k - 1, i + len));
    }
    return finalMinOps[i][k] - 1;
  }
public:
  int minimumChanges(string s, int k) {
    int n = s.size();
    memset(semiMinOps, 1, sizeof(semiMinOps));
    for (int d = 1; d <= n / 2; ++d) {
      memset(divMinOps, 0, sizeof(divMinOps));
      for (int len = 2 * d; len <= n; len += d) {
        for (int i = 0; i + len <= n; ++i) {
          int ops = 0;
          for (int off = 0; off < d; ++off) {
            ops += s[i + off] != s[i + len - (d - off)];
          }
          divMinOps[i][len] = ops + divMinOps[i + d][len - 2 * d];
          semiMinOps[i][len] = min(semiMinOps[i][len], divMinOps[i][len]);
        }
      }
    }
    return dfs(s, k, 0);
  }
};

int main() {
  return 0;
}
