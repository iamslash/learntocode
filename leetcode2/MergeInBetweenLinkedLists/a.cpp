/* Copyright (C) 2020 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 424ms 16.67% 94.9MB 66.67%
// linked list
// O(N) O(1)
class Solution {
 public:
  ListNode* mergeInBetween(ListNode *h1, int a, int b,
                           ListNode *h2) {
    ListNode alpha(0, h1), beta(0, h2);
    ListNode *beforeA = NULL, *afterB = NULL, *endH2 = NULL;
    // get endH2
    ListNode *beforeP = &beta, *p = h2;
    while (p) {
      beforeP = p;
      p = p->next;
    }
    endH2 = beforeP;
    // get afterB
    p = h1;
    while (b-- > 0) {
      p = p->next;
    }
    afterB = p->next;
    // get beforeA
    beforeP = &alpha, p = h1;
    while (a-- > 0) {
      beforeP = p;
      p = p->next;
    }
    beforeA = beforeP;
    
    beforeA->next = h2;
    endH2->next = afterB;
    return h1;
  }
};

// 408ms 33.33% 95MB 66.67%
class Solution {
 public:
  ListNode* mergeInBetween(ListNode* h1, int a, int b, ListNode* h2) {
    ListNode *pa = h1, *pb = NULL;
    for (int i = 1; i <= b; ++i) {
      if (i < a) {
        pa = pa->next;
      } else if (i == a) {
        pb = pa->next;
      } else {
        pb = pb->next;
      }
    }
    pa->next = h2;
    while (h2->next != NULL) {
      h2 = h2->next;
    }
    h2->next = pb->next;
    return h1;
  }
};
