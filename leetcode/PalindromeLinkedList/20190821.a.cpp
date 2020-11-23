/* Copyright (C) 2019 by iamslash */

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* y) : val(x), next(y) {}
};

//   p 
//     n
//     h
// 1 2 3 4 5
//
// T:O(N), S:O(1)
// 20ms, 56.83%
class Solution {
 private:
  ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
  
 public:
  bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL)
      return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while (slow) {
      if (head->val != slow->val)
        return false;
      head = head->next;
      slow = slow->next;
    }
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  // ListNode* h = new ListNode(1, new ListNode(2));
  ListNode* h = new ListNode(1, new ListNode(2, new ListNode(1)));

  Solution sln;
  printb(sln.isPalindrome(h));
  
  return 0;
}
