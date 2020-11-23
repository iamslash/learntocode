/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/117/linked-list/840

#include <cstdio>
#include <algorithm>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* p) : val(x), next(p) {}
};

//
// 4 2 1 3
class Solution {
 public:
  int getcnt(ListNode* h) {
    int r = 0;
    while (h) {
      ++r;
      h = h->next;
    }
    return r;
  }
  ListNode* sortList(ListNode* h) {
    int       k  = 1;                   // block size
    int       i  = 0;                   // index of list
    int       n  = getcnt(h);           // count of h
    int       j  = 0;
    int       na = 0, nb = 0;           // count of block a, b
    ListNode* pa = NULL, *pb = NULL, *tmp = NULL, *p = NULL;
    ListNode* pl = NULL;                // last pointer
    ListNode r(0);
    r.next = h;

    while (k < n) {
      i  = 0;
      pl = &r;
      p  = r.next;

      
      while (i < n) {
        // for last members lesser than block size
        na = std::min(n - i, k);
        nb = std::min(n - i - na, k);

        // split
        pa = p;
        if (nb != 0) {          
          // forward to set pb
          for (j = 0; j < na-1; ++j) {
            p = p->next;
          }
          pb = p->next;
          p->next = NULL;
          p = pb;

          for (j = 0; j < nb-1; ++j) {
            p = p->next;
          }
          tmp = p->next;
          p->next = NULL;
          p = tmp;
        }

        // merge
        while (pa || pb) {          
          if (pb == NULL || (pa != NULL && pa->val <= pb->val)) {
            pl->next = pa;
            pl = pl->next;
            pa = pa->next;
          } else {
            pl->next = pb;
            pl = pl->next;
            pb = pb->next;
          }
        }
        
        pl->next = NULL;
        i += na + nb;
        
      }
      k <<= 1;
    }    
    return r.next;
  }
};

int main() {
  ListNode* p = new ListNode(4,
                             new ListNode(2,
                                          new ListNode(1,
                                                       new ListNode(3))));
  Solution s;
  ListNode* r = s.sortList(p);

  while (r) {
    printf("%d ", r->val);
    r = r->next;
  }
  printf("\n");
  return 0;
}
