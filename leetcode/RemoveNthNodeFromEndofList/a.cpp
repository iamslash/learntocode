// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* pnext) : val(x), next(pnext) {}
};


// b       
//     h
// 1 2
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* ph, int n) {
    if (n <= 0)
      return ph;
    ListNode* pr = ph;
    ListNode* pb = ph;

    int i = n;
    while (ph->next) {
      // printf("n:%d h:%d\n", n, ph->val);
      ph = ph->next;
      if (i > 0) {
        --i;
      } else {
        pb = pb->next;
      }
    }
    if (i == 0)
      pb->next = pb->next->next;
    else
      pr = pb->next;

    return pr;
  }
};

int main() {
  Solution s;
  // ListNode* p = new ListNode(1,
  //                 new ListNode(2,
  //                   new ListNode(3,
  //                     new ListNode(4,
  //                       new ListNode(5)))));
  ListNode* p = new ListNode(1);
  int n = 1;
  // ListNode* p = new ListNode(1, new ListNode(2));
  // int n = 2;
  ListNode* pp = s.removeNthFromEnd(p, n);
  ListNode* phead = pp;
  while (phead) {
    printf("%d ", phead->val);
    phead = phead->next;
  }
  return 0;
}
