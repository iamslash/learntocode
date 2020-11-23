/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};

void printl(ListNode* u) {
  while (u) {
    printf("%d ", u->val);
    u = u->next;
  }
}

// 4ms 100.00% 8.7MB 6.52%
// reverse
// O(N) O(1)
class Solution {
 private:
  ListNode* reverse(ListNode* u) {
    ListNode* b = NULL;
    ListNode* v = NULL;
    while (u) {
      v = u->next;
      u->next = b;
      b = u;
      u = v;
    }
    return b;
  }
 public:
  ListNode* plusOne(ListNode* u) {
    ListNode* r = reverse(u);
    
    ListNode* p = r;
    int c = 1;
    while (p) {
      p->val += 1;
      if (p->val <= 9) {
        break;
      } else {
        p->val = 0;
        if (!p->next) {
          p->next = new ListNode(1);
          break;
        }
      }
      p = p->next;
    }
    return reverse(r);
  }
};

int main() {

  // ListNode* u = new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode* u = new ListNode(9);
  Solution sln;
  u = sln.plusOne(u);
  printl(u);
  
  return 0;
}

