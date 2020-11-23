// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void deleteNode(ListNode* node) {
    ListNode* t;
    for (; node->next; t = node, node = node->next) {
      node->val = node->next->val;
    }
    t->next = nullptr;
  }
};

int main() {
  return 0;
}
