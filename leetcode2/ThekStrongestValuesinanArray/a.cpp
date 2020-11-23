/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 664ms 74.46% 82.6MB 100.00%
// sort
// O(NlgN) O(K)
class Solution {
 public:
  vector<int> getStrongest(vector<int>& A, int k) {
    int n = A.size(), i = 0, j = n - 1;
    sort(A.begin(), A.end());
    int med = A[(n-1)/2];
    vector<int> ans;
    while (i <= j && k-- > 0) {
      int strongA = abs(A[i] - med);
      int strongB = abs(A[j] - med); 
      if (strongA > strongB || (strongA == strongB && A[i] > A[j])) {
        ans.push_back(A[i++]);  
      } else {
        ans.push_back(A[j--]);
      }
    }
    return ans;
  }
};
