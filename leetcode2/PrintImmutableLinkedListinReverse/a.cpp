/* Copyright (C) 2020 by iamslash */

#include <cstdio>

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

// 4ms 73.27% 6.7MB 100.00%
// recursion
// O(N) O(N)
class Solution {
 public:
  void printLinkedListInReverse(ImmutableListNode* u) {
    if (u == nullptr)
      return;
    printLinkedListInReverse(u->getNext());
    u->printValue();
  }
};

int main() {
  return 0;
}
