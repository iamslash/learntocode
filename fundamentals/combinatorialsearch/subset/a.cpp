/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// backtracking
// O(2^N) O(N)
class Solution {
 private:
  vector<int> m_comb;
  vector<vector<int>> m_rslt;
  int m_n;
  void solve(int pos) {
    // for (int i = 0; i < pos; ++i) 
    //   printf("_");
    // printf("%d\n", pos);
    
    // base
    if (pos > 0) {
      m_rslt.push_back(m_comb);
    }
    // recursion
    for (int i = pos + 1; i <= m_n; ++i) {
      m_comb.push_back(i);
      solve(i);
      m_comb.pop_back();
    }
  }
 public:
  vector<vector<int>> subset(int n) {
    m_n = n;
    solve(0);
    m_rslt.push_back({});
    return m_rslt;
  }
};

// bit manipulation
// O(2^N) O(N)
class Solution {
 public:
  vector<vector<int>> subset(int n) {
    vector<vector<int>> ans;
    for (int bm = 1; bm < (1 << n); ++bm) {
      vector<int> subset;
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & bm) {
          subset.push_back(i+1);
        }
      }
      ans.push_back(subset);
    }
    return ans;
  }
};

int main() {

  Solution sln;
  auto rslt = sln.subset(4);
  for (const auto& l : rslt) {
    for (int a : l) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
