/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stack>

//   
// 6 0 8 2 1 5
// 0 1 2 3 4 5


// 0 1 2 5 6 8
// m
// 1 4 3 5 0 2
//         i

// // Runtime Error :
// //  I do not understand when I use "return A[i] <= A[j]" instead of
// //  "return A[i] < A[j]" inside lambda function
// //
// // sorting of index
// // O(NlgN) O(N)
// class Solution {
//  public:
//   int maxWidthRamp(std::vector<int>& A) {
//     int n = A.size(), ans = 0, low = n;
//     std::vector<int> I(n);
//     std::iota(I.begin(), I.end(), 0);
//     std::sort(I.begin(), I.end(), [&A](int i, int j) {
//         return A[i] <= A[j];
//       });    
//     for (int idx : I) {
//       //printf("%2d ", idx);
//       ans = std::max(ans, idx - low);
//       low = std::min(low, idx);
//     }
//     printf("\n");
//     return ans;
//   }
// };

//    t
// A: 6 0 8 2 1 5
//        i
// s: 0
// a: 4

// 60ms 88.85% 12.9MB 77.94%
// decreasing stack
// O(N) O(N)
class Solution {
 public:
  int maxWidthRamp(std::vector<int>& A) {
    std::stack<int> stck;
    int ans = 0, n = A.size();
    for (int i = 0; i < n; ++i) {
      if (stck.empty() || A[stck.top()] > A[i])
        stck.push(i);
    }
    for (int i = n - 1; i > ans; --i) {
      while (stck.size() && A[stck.top()] <= A[i]) {
        ans = std::max(ans, i - stck.top());
        stck.pop();
      }
    }
    return ans;
  }
};

int main() {
  std::vector<int> A =
      {3,28,15,1,4,12,6,19,8,15,3,9,6,4,13,12,6,12,10,1,2,1,4,1,4,0,0,1,1,0};
  Solution sln;
  printf("%d\n", sln.maxWidthRamp(A));
  
  return 0;
}
