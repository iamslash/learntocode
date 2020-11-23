/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/

#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* pr = NULL;
    ListNode* pt = NULL;
    int c = 0; // carry
    while (l1 != NULL || l2 != NULL) {
      int a = l1 == NULL ? 0 : l1->val;
      int b = l2 == NULL ? 0 : l2->val;
      int s = (a + b + c) % 10;
      c     = (a + b + c) / 10;

      if (pr == NULL) {
        pr = new ListNode(s);
        pt = pr;
      } else {
        pt->next = new ListNode(s);
        pt = pt->next;
      }

      if (l1 != NULL)
        l1 = l1->next;
      if (l2 != NULL)
        l2 = l2->next;
      // printf("s:%d c:%d\n", s, c);
    }
    if (c > 0)
      pt->next = new ListNode(c);      
    return pr;
  }
};

int main() {
  ListNode* p1 = new ListNode(2);
  p1->next = new ListNode(4);
  p1->next->next = new ListNode(3);

  ListNode* p2 = new ListNode(5);
  p2->next = new ListNode(6);
  p2->next->next = new ListNode(4);

  Solution s;
  ListNode* p = s.addTwoNumbers(p1, p2);
  while (p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  return 0;
}
