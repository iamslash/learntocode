/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

class Solution {
 public:
  bool validateStackSequences(std::vector<int>& pushed,
                              std::vector<int>& popped) {
    std::stack<int> stck;
    int i = 0;
    for (int x : pushed) {
      stck.push(x);
      while (stck.size() && stck.top() == popped[i]) {
        stck.pop();
        ++i;
      }
    }
    return i == popped.size();     
  }
};

int main() {
  return 0;
}
