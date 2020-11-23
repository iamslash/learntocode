/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/rotate-list/description/

#include <cstdio>


struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// 1 2 3 4 5
class Solution {
 public:
  ListNode* rotateRight(ListNode* h, int k) {
    if (!h)
      return h;
    int n = 0;
    ListNode* p = h;
    ListNode* t = h;
    while (p)
      ++n, t = p, p = p->next;
    t->next = h;
    if (k %= n) {
      for (int i = 0; i < n-k; ++i)
        t = t->next;
    }
    ListNode* r = t->next;
    t->next = NULL;
    return r;
  }
};

int main() {
  ListNode* h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  int k = 2;

  Solution s;
  const auto* r = s.rotateRight(h, k);

  while (r) {
    printf("%d ", r->val);
    r = r->next;
  }
  printf("\n");
    

  return 0;
}
