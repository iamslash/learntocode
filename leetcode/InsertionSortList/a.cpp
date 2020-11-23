// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <limits>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

//   h
// v 2 4 1 3
// a
//   p
//     b
//       q
class Solution {
 public:
  ListNode* insertionSortList(ListNode* h) {
    if (h == NULL || h->next == NULL)
      return h;
    ListNode v(std::numeric_limits<int>::min());
    v.next = h;

    ListNode* a = &v, *p = h, *b = h, *q = h->next;
    while (q) {
      a = &v;
      p = a->next;
      //printf("p:%d b:%d q:%d\n", p->val, b->val, q->val);
      
      // forward b, p until need to swap
      while (p != q && p->val < q->val) {
        a = a->next;
        p = p->next;
      }
      //printf(" a:%d p:%d\n", a->val, p->val);

      // foward q or swap
      if (p != q) {
        b->next = q->next;
        a->next = q;
        q->next = p;

        q = b->next;
      } else {
        b = q;
        q = q->next;
      }
    }
    return v.next;
  }
};

int main() {
  ListNode* h = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));

  Solution s;
  h = s.insertionSortList(h);
  while (h) {
    printf("%d ", h->val);
    h = h->next;
  }
  printf("\n");
  return 0;
}


