/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

// 84ms 72.34% 17.6MB 23.52%
// two heap
// O(NlgN) o(N)
class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& A, int k) {
    vector<double> ans;
    multiset<int> maxSet, minSet;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      // Insert new one
      if (maxSet.empty() || A[i] >= *maxSet.begin()) {
        maxSet.insert(A[i]);
      } else {
        minSet.insert(A[i]);
      }
      // Remove old one
      if (i >= k) {
        int u = A[i-k];
        if (u >= *maxSet.begin()) {
          maxSet.erase(maxSet.find(u));
        } else {
          minSet.erase(minSet.find(u));
        }
      }
      // Rebalance
      while (maxSet.size() < minSet.size()) {
        maxSet.insert(*minSet.rbegin());
        minSet.erase(--minSet.end());
      }
      while (maxSet.size() > minSet.size() + 1) {
        minSet.insert(*maxSet.begin());
        maxSet.erase(maxSet.begin());
      }
      // Push median
      if (i >= k - 1) {
        if (k & 1) {
          ans.push_back(*maxSet.begin());
        } else {
          ans.push_back(((double)*maxSet.begin() + *minSet.rbegin()) / 2);
        }
      }
    }
    return ans;
  }
};
