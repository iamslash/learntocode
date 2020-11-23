// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/784/

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
  explicit ListNode(int x) : val(x), next(NULL) {}
};
//         x 
//    h
// // 1 -> 2 -> 3 -> 4 -> 5
//         y
//         z
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head) {
      ListNode* p0 = head, *p1 = head->next, *pp = p1;
      while (p1 && p1->next) {
        p0->next = p1->next;
        p0 = p0->next;
        p1->next = p0->next;
        p1 = p1->next;
      }
      p0->next = pp;
    }
    return head;
  }
};

void dump(ListNode* p) {
  while (p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
}

int main() {
  ListNode*  h = NULL;
  ListNode** t = &h;
  for (int i = 0; i < 5; ++i) {
    *t = new ListNode(i+1);
    t = &((*t)->next);
  }
  Solution s;
  ListNode* p = s.oddEvenList(h);
  dump(p);
  return 0;
}
