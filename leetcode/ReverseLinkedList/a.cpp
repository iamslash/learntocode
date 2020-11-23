/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


//     p h
//   1 2
//       n

// 8ms 77.52% 9MB 100.00%
class Solution {
 public:
  ListNode* reverseList(ListNode* h) {
    ListNode* p = NULL;
    ListNode* n;
    while (h) {
      n       = h->next;
      h->next = p;
      p       = h;
      h       = n;
    }
    return p;
  }
};

int main() {
  return 0;
}
