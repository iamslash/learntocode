/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// p h 
//   2 1
//     t    

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 24ms 66.45% 12.9MB 43.10%
class Solution {
 private:
  ListNode* reverse(ListNode* h) {
    ListNode* p = NULL;
    ListNode* n = NULL;
    while (h) {
      n = h->next;
      h->next = p;
      p = h;
      h = n;
    }
    return p;
  }
 public:
  bool isPalindrome(ListNode* h) {
    if (!h || !h->next)
        return true;
    ListNode *s = h, *f = h;
    while (f->next && f->next->next) {
      s = s->next;
      f = f->next->next;
    }
    s->next = reverse(s->next);
    f = s->next, s = h;
    while (f) {
      if (s->val != f->val)
        return false;
      s = s->next;
      f = f->next;
    }
    return true;
  }
};

int main() {
  return 0;
}
