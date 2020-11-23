// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/swap-nodes-in-pairs/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* y) : val(x), next(y) {}
};

//         t
//   b
//       h
// 2 1 4 3 
class Solution {
 public:
  ListNode* swapPairs(ListNode* h) {
    ListNode* r = h;
    ListNode* b = h;
    
    while (h && h->next) {
      // swap
      if (b == h) {
        ListNode* t = h->next->next;
        r = h->next;
        r->next = h;
        h->next = t;
      } else {
        b->next = h->next;
        h->next = h->next->next;
        b->next->next = h;
      }
      b = h;
      h = h->next;
    }

    return r;
  }
};

int main() {
  // ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3,
  //   new ListNode(4))));
  ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3)));

  Solution s;
  ListNode* p = s.swapPairs(h);
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  return 0;
}
