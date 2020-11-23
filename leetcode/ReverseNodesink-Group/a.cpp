/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* y) : val(x), next(y) {}
};

//  b
// -1 1 2 3 4 5
//  p
//    c
//      n
// O(N) O(1)
// 20ms 98.80%
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* h, int k) {
    if (h == NULL || k == 1)
      return h;
    int cnt = 0;
    ListNode* bfh = new ListNode(-1); // before head
    bfh->next = h;
    ListNode* cur = bfh;   // current
    ListNode* nxt = NULL;  // next
    ListNode* prv = bfh;   // prev
    // get cnt
    while (cur = cur->next)
      cnt++;
    while (cnt >= k) {
      cur = prv->next;
      nxt = cur->next;
      for (int i = 1; i < k; ++i) {
        cur->next = nxt->next;
        nxt->next = prv->next;
        prv->next = nxt;
        nxt       = cur->next;
      }
      prv = cur;
      cnt -= k;
    }
    return bfh->next;
  }
};

int main() {
  ListNode* h = new ListNode(
      1, new ListNode(
          2, new ListNode(
              3, new ListNode(
                  4, new ListNode(
                      5)))));
  Solution sln;
  h = sln.reverseKGroup(h, 2);
  while (h) {
    printf("%d ", h->val);
    h = h->next;
  }
  printf("\n");
  return 0;
}
