/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* n) : val(x), next(n) {}
};

//         p
//           a
//             b
// 1 2 3 3 4 4 5
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* h) {
    ListNode** p = &h;
    ListNode*  a;
    ListNode*  b;

    while (*p) {
      a = (*p)->next;
      if (a && (*p)->val == a->val) {
        do {
          b = a->next;
          delete a;
          a = b;
        } while (a && (*p)->val == a->val);
        delete *p;
        *p = a;
      } else {
        p = &(*p)->next;
      }
    }
    
    return h;
  }
};

int main() {
  ListNode* p = new ListNode(1,
                             new ListNode(2,
                                          new ListNode(3,
                                                      new ListNode(3,
                                                                    new ListNode(4,
                                                                                 new ListNode(4,
                                                                                              new ListNode(5)))))));
  Solution s;
  ListNode* r = s.deleteDuplicates(p);
  while (r) {
    printf("%d ", r->val);
    r = r->next;
  }
  printf("\n");
  
  return 0;
}
