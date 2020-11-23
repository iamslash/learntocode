/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/partition-list/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* h, int x) {
    ListNode  n0(0);
    ListNode  n1(0);
    ListNode* p0 = &n0;
    ListNode* p1 = &n1;

    while (h) {
      if (h->val < x) {
        p0 = p0->next = h;
      } else {
        p1 = p1->next = h;
      }
      h = h->next;
    }
    p1->next = NULL;
    p0->next = n1.next;
    h = n0.next;
    
    return h;
  }
};

int main() {
  ListNode* h = new ListNode(1,
                             new ListNode(4,
                             new ListNode(3,
                             new ListNode(2,
                             new ListNode(5,
                                          new ListNode(2))))));
  int x = 3;
  Solution s;
  ListNode* p = s.partition(h, x);

  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  
  return 0;
}
