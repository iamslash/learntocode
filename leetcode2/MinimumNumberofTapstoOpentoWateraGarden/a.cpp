/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// greedy
// O(NlgN) O(N)
void printv(vector<vector<int>>& V) {
  for (auto& v : V) {    
    printf("%d,%d ", v[0], v[1]);
  }
  printf("\n");
}
class Solution {
 public:
  int minTaps(int n, vector<int>& R) {
    int ans = 0;
    vector<vector<int>> coolers;
    for (int i = 0; i < n+1; ++i) {
        coolers.push_back({i-R[i], i+R[i]});
    }
    sort(coolers.begin(), coolers.end());
    // printv(coolers);
    int beg = 0, end = 0;
    for (int i = 0; i < n+1 && beg < n; beg = end) {
      while (i < n+1 && coolers[i][0] <= beg) {
        end = max(end, coolers[i++][1]);
      }
      // printf("i:%d, %d %d\n", i, beg, end);
      if (beg == end)
        return -1;
      ans++;
    }
    return ans;
  }
};
