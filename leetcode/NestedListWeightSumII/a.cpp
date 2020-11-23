/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const std::vector<NestedInteger> &getList() const;
};

// 2 cycles
// 4ms 100.00% 12.2MB 100.00%
class Solution {
 private:
  int getDepth(const std::vector<NestedInteger>& nl) {
    if (nl.empty())
      return 1;
    int r = 0;
    for (auto& ni : nl) {
      if (!ni.isInteger())
        r = std::max(r, getDepth(ni.getList()));
    }
    return r + 1;
  }
  int solve(const std::vector<NestedInteger>& nl, int depth, int maxdepth) {
    if (nl.empty())
      return 0;
    int r = 0;
    for (auto& ni : nl) {
      if (ni.isInteger())
        r += (maxdepth - depth) * ni.getInteger();
      else
        r += solve(ni.getList(), depth+1, maxdepth);
    }
    return r;
  }
 public:
  int depthSumInverse(std::vector<NestedInteger>& nl) {
    int depth = getDepth(nl);
    return solve(nl, 0, depth);
  }
};

int main() {
  return 0;
}
