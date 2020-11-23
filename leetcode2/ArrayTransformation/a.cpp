/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//   
// A: 6 3 3 4
// M: 3
// m: 2

// A: 1 6 3 4 3 5
// M: 6
// m: 3

//      i
// A: 2 1 2 1 1 2 2 1
// A: 2 2 2 1 1 2 2 1   

// brute force
// O(N) O(1)
class Solution {
 public:
  vector<int> transformArray(vector<int>& A) {
    while (true) {
      bool changed = false;
      vector<int> B = A;
      for (int i = 1; i < A.size()-1; ++i) {
        if (B[i-1] > B[i] && B[i] < B[i+1]) {
          A[i]++;
          changed = true;
        } else if (B[i-1] < B[i] && B[i] > B[i+1]) {
          A[i]--;
          changed = true;
        }
      }
      if (!changed)
        break;
    }
    return A;
  }
};
