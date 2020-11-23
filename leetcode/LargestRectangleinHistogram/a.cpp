/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

//                r          
//    H: -1 2 1 2 0
//            i
//        l
// rslt: 0
// stck: 0 1
//    i: 
//    l:  

// stack
// O(N) O(N)
// 12ms 96.88%
class Solution {
 public:
  int largestRectangleArea(std::vector<int>& H) {
    if (H.empty())
      return 0;
    int rslt = 0;
    std::stack<int> stck;
    stck.push(0);
    H.insert(H.begin(), -1);
    H.push_back(0);
    for (int r = 1; r < H.size(); ++r) {
      while (H[stck.top()] > H[r]) {
        int i = stck.top(); stck.pop();
        int l = stck.top();
        rslt = std::max(rslt, H[i] * (r - l - 1));
      }
      stck.push(r);
    }        
    return rslt;
  }
};

int main() {
  // std::vector<int> H = {2,1,5,6,2,3};
  std::vector<int> H = {2,1,2};
  Solution sln;
  printf("%d\n", sln.largestRectangleArea(H));
  
  return 0;
}
