/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//    k: 3
//       i
// code: 5 7 1 4
//         j
//  sum:   

// 4ms 100.00% 8.7MB 100.00%
// brute force
// O(N^2) O(N)
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> ans = vector<int>(n);
    if (k > 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = i+1, m = 0; m < k; ++j, ++m) {
          int jj = j % n;
          ans[i] += code[jj];
        }
      }      
    } else if (k < 0) {
      for (int i = 0; i < n; ++i) {        
        for (int m = 0, j = i-1; m > k; --m, --j) {
          int jj = (j + n) % n;          
          ans[i] += code[jj];
        }
      }            
    }
    return ans;
  }
};

// 4ms 100.00% 8.6MB 100.00%
// brute force
// O(N^2) O(N)
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> ans = vector<int>(n);
    for (int i = 0; i < n && k; ++i) {
      int sum = 0;
      for (int j = min(1, k); j <= max(k, -1); ++j) {
        sum += code[(i + j + n) % n];
      }
      ans[i] = sum;
    }
    return ans;
  }
};
