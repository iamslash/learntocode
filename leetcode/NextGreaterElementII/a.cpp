/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

// // 136ms, 31.29%
// // O(N^2) O(N)
// class Solution {
//  private:
//   int getBiggerNum(const std::vector<int>& W, int n, int i, int a) {
//     for (int j = i + 1; j < i + n; ++j) {
//       if (W[i] < W[j])
//         return W[j];
//     }
//     return -1;
//   }
//  public:
//   std::vector<int> nextGreaterElements(std::vector<int>& V) {
//     std::vector<int> W(V.begin(), V.end());
//     W.insert(W.end(), V.begin(), V.end());
//     std::vector<int> rslt;
//     for (int i = 0; i < V.size(); ++i) {
//       rslt.push_back(getBiggerNum(W, V.size(), i, V[i]));
//     }
//     return rslt;
//   }
// };


//              i                 
// V: 5 4 3 2 1 5 4 3 2 1
// s: 0    
// r: - 5 5 5 5
//
// stack
// 88ms 99.32%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> nextGreaterElements(std::vector<int>& V) {
    int n = V.size();
    std::vector<int> rslt(n, -1);
    std::stack<int> stck;
    for (int i = 0; i < n * 2; ++i) {
      int num = V[i % n];
      while (!stck.empty() && V[stck.top()] < num) {
        rslt[stck.top()] = num;
        stck.pop();
      }
      if (i < n)
        stck.push(i);
    }
    return rslt;
  }
};

int main() {

  // std::vector<int> V = {1, 2, 1};
  std::vector<int> V = {5, 4, 3, 2, 1};
  Solution sln;
  auto rslt = sln.nextGreaterElements(V);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
