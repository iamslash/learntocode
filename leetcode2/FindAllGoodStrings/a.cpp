/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// 20ms 87.74% 7.1MB 50.00%
// recursive dynamic programming
// O(N*M*2*2*26) O(N*M*2*2)
// O(NM) O(NM)
#define MOD 1000000007
class Solution {
 private:
  int C[501][51][2][2] = {};
  vector<int> buildLps(const string& a) {
    int n = a.size();
    vector<int> lps = vector<int>(n);
    for (int i = 1, j = 0; i < n; ++i) {
      while (j > 0 && a[i] != a[j])
        j = lps[j-1];
      if (a[i] == a[j])
        lps[i] = ++j;
    }
    return lps;
  }
  int dfs(int i, int evilMatched, bool leftBound, bool rightBound,
          int n, string& a, string& b, string& evil, const vector<int>& lps) {
    // base
    if (evilMatched == evil.size())
      return 0;
    if (i == n)
      return 1;
    // memo
    int& r = C[i][evilMatched][leftBound][rightBound];
    if (r > 0)
      return r;
    char from = leftBound ? a[i] : 'a';
    char to = rightBound ? b[i] : 'z';
    r = 0;
    for (char c = from; c <= to; ++c) {
      int j = evilMatched;
      while (j > 0 && evil[j] != c)
        j = lps[j - 1];
      if (c == evil[j])
        ++j;
      r += dfs(i + 1, j, leftBound && (c == from), rightBound && (c == to),
               n, a, b, evil, lps);
      r %= MOD;
    }
    return r;
  }
 public:
  int findGoodStrings(int n, string a, string b, string evil) {
    vector<int> lps = buildLps(evil);
    return dfs(0, 0, true, true, n, a, b, evil, lps);
    
  }
};
