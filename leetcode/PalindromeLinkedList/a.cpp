/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
//   s f
// 1 2 1

//   s f
// 1 2 2 1
//     s   f
// 1 2 3 2 1


//       b h
//   1 2 3
//         n
//
// n = h->next
// h->next = b
// b = h
// h = n

// 20ms 91.08% 12.7MB 79.31%
// reverse
// O(N) O(1)
class Solution {
 private:
  ListNode* reverse(ListNode* h) {
    ListNode* b = NULL;
    while (h) {
      ListNode* n = h->next;
      h->next = b;
      b = h;
      h = n;
    }
    return b;
  }
 public:
  bool isPalindrome(ListNode* h) {
    if (h == NULL || h->next == NULL)
      return true;
    ListNode* s = h;
    ListNode* f = h;
    while (f->next && f->next->next) {
      s = s->next;
      f = f->next->next;
    }
    f = reverse(s->next);
    s->next = NULL;
    s = h;
    while (s && f) {
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
