/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* y) : val(x), next(y) {}
};

// 7 2 4 3
//   5 6 4
// use stack
// 80ms 1.88%
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
    std::stack<int> stcka;
    std::stack<int> stckb;
    while (a != NULL) {
      stcka.push(a->val);
      a = a->next;
    }
    while (b != NULL) {
      stckb.push(b->val);
      b = b->next;
    }
    int sum = 0;
    ListNode* p = new ListNode(0);
    while (!stcka.empty() || !stckb.empty()) {
      if (!stcka.empty()) {
        sum += stcka.top(); stcka.pop();
      }
      if (!stckb.empty()) {
        sum += stckb.top(); stckb.pop();
      }
      p->val = sum % 10;
      int carry = sum / 10;
      ListNode* h = new ListNode(carry);
      h->next = p;
      p = h;
      sum = carry;
    }
    return p->val == 0 ? p->next : p;
  }
};

void printl(ListNode* p) {
  if (p) {
    printf("%d ", p->val);
    printl(p->next);
  }
}

int main() {
  ListNode* a = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
  ListNode* b = new ListNode(5, new ListNode(6, new ListNode(4)));
  Solution sln;
  ListNode* r = sln.addTwoNumbers(a, b);
  printl(r);
  printf("\n");
  return 0;
}
