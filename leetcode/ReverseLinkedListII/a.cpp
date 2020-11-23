// Copyright (C) 2018 by iamslash

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* h, int m, int n) {
    //   f
    // l
    //           b
    //             p
    // v 1 2 3 4 5
    // m:1 n: 5
    ListNode v(0);  // virtual node
    v.next = h;
    ListNode* b = &v;
    ListNode* p = &v;  // iterator pointer
    ListNode* l = &v;  // left block end pointer
    ListNode* f = v.next;  // mid block start pointer
    ListNode* t = NULL;

    n -= m - 1;
    while (--m) {
      p = p->next;
    }
    l = p;
    f = l->next;
    b = p;
    p = p->next;
    while (n--) {
      t = p->next;
      p->next = b;
      b = p;
      p = t;
    }
    l->next = b;
    f->next = p;
    return v.next;
  }
};

int main() {

  ListNode* h = new ListNode(1,
                             new ListNode(2,
                                          new ListNode(3,
                                                       new ListNode(4,
                                                                    new ListNode(5)))));
  int m = 2, n = 4;
  
  Solution s;
  ListNode* p = s.reverseBetween(h, m, n);

  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("\n");
  return 0;
}
