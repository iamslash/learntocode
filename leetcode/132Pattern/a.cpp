/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>
#include <limits>


// 2 3 1


//        i
// V: 1 2 3
// s: 3
// o: 1 2
//    p
// 24ms 63.15%
class Solution {
 public:
  bool find132pattern(vector<int>& V) {
    std::stack<int> stck;
    int prev = std::numeric_limits<int>::min();

    for (auto it = V.rbegin(); it != V.rend(); ++it) {
      while (!stck.empty() && stck.top() < *it) {
        if (prev > stck.top())
          return true;
        prev = stck.top(); stck.pop();        
      }
      stck.push(*it);
    }

    return !stck.empty() && prev > stck.top();
  }
};

int main() {
  return 0;
}
