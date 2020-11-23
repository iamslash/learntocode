// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/linked-list-cycle-ii/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* n) : val(x), next(n) {}
};

// f                                                          
// s            
// 1 2 
//         
class Solution {
 public:
  ListNode *detectCycle(ListNode* h) {
    if (h == NULL)
      return NULL;
    ListNode* slow = h;
    ListNode* fast = h;
    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        break;
    }
    if (slow == NULL || fast == NULL || fast->next == NULL)
      return NULL;
    fast = h;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};

int main() {
  return 0;
}
