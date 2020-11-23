/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//    A: 7 4
//    B: 7 7 7 7
//             i
// umpA: 7
//       3
//  ans: 6

// 800 ms 22.51% 16.4MB 53.27%
// hash map
// O(AB) O(N)
class Solution {
 private:
  int cntPair(int64_t aa, vector<int>& A) {
    int ans = 0;
    unordered_map<int, int> ump;
    for (int a : A) {
      int rem = aa % a;
      if (rem != 0)
        continue;
      int quo = aa / a;    
      ans += ump[quo];
      ump[a]++;
    }
    return ans;
  }
 public:
  int numTriplets(vector<int>& A, vector<int>& B) {
    int ans = accumulate(A.begin(), A.end(), 0, [&](int s, int64_t a) {
                                                  return s + cntPair(a*a, B);
                                                });
    ans += accumulate(B.begin(), B.end(), 0, [&](int s, int64_t b) {
                                               return s + cntPair(b*b, A);
                                             });
    return ans;
  }
};
