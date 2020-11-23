/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

// V: 1 4 2 5 3
//            i
// s: 1 2 3
// r: 11

// 76ms 76.15% 15.4MB 70.00%
// O(N) O(N)
class Solution {
 public:
  int validSubarrays(std::vector<int>& V) {
    std::stack<int> stck;
    int r = 0;
    for (int a : V) {
      while (stck.size() && stck.top() > a)
        stck.pop();
      stck.push(a);
      r += stck.size();
    }
    return r;
  }
};
 
int main() {
  return 0;
}
