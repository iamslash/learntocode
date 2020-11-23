/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// 12ms 99.37% 9.6MB 35.62%
// O(N) O(1)
class Solution {
 public:
  std::vector<ListNode*> splitListToParts(ListNode* h, int k) {
    std::vector<ListNode*> slots(k, NULL);
    if (!h)
      return slots;
    // get n
    int n = 0;
    ListNode* p = h;
    while (p) {
      ++n;
      p = p->next;
    }
    int quo = n / k;
    int rem = n % k;
    // partition
    ListNode* t = new ListNode(0);
    ListNode* b = t;
    p = h;
    b->next = p;
    for (int i = 0; i < slots.size(); ++i) {
      slots[i] = p;
      for (int j = 0; j < quo; ++j) {
        b = b->next;
        p = p->next;
      }
      if (i < rem) {
        b = b->next;
        p = p->next;
      }
      b->next = NULL;
      b = t;
      b->next = p;
    }
    return slots;
  }
};

void printl(ListNode* h) {
  ListNode* p = h;
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("N");
}

int main() {

  ListNode* h = new ListNode(1);
  ListNode* p = h;
  for (int i = 2; i <= 10 ; ++i) {
    p->next = new ListNode(i);
    p = p->next;
  }
  int k = 3;
  Solution sln;
  auto r = sln.splitListToParts(h, k);
  for (auto* u : r) {
    printl(u);
    printf("\n");
  }
  
  return 0;
}
