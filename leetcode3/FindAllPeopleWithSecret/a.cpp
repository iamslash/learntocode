/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 616ms 98.85% 139.3MB 85.06%
// disjoint set
// O(NlgN) O(N)
class MergeFind {
  vector<int> prnts;
public:
  MergeFind(int n) : prnts(n) {
    iota(begin(prnts), end(prnts), 0);
  }
  void merge(int a, int b) {
    prnts[find(b)] = find(a);
  }
  int find(int a) {
    return prnts[a] == a ? a : (prnts[a] = find(prnts[a]));
  }
  void reset(int a) {
    prnts[a] = a;
  }
  void dump() {
    for (int a : prnts) {
      printf("%d ", a);
    }
    printf("\n");
  }
};
class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    sort(begin(meetings), end(meetings),
         [](const vector<int>& a, const vector<int>& b) {
           return a[2] < b[2];
         });
    MergeFind mf(n);
    mf.merge(0, firstPerson);
    vector<int> pool;
    int m = meetings.size(), i = 0;
    while (i < m) {
      pool.clear();
      int time = meetings[i][2];          
      while (i < m && meetings[i][2] == time) {
        int u = meetings[i][0];
        int v = meetings[i][1];
        mf.merge(u, v);
        pool.push_back(u);
        pool.push_back(v);
        i++;
      }
      for (int u : pool) {
        if (mf.find(0) != mf.find(u)) {
          mf.reset(u);
        }
      }
    }
    vector<int> ans;
    for (int u = 0; u < n; ++u) {
      if (mf.find(0) == mf.find(u)) {
        ans.push_back(u);
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
