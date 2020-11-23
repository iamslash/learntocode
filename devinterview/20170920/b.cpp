// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Question. Remove Nth node from end of list

// Given a single linked list, remove the n-th node from the end of
// list and return its head.

// ex)
//     Given linked list : 1->2->3->4->5
//     n = 2

//     Return linked list : 1->2->3->5

// Notes.
//     - Given n will always be valid
//     - Try to do this in one pass

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode** t1 = &head, *t2 = head;
      for(int i = 1; i < n; ++i)
      {
        t2 = t2->next;
      }
      while(t2->next != NULL)
      {
        t1 = &((*t1)->next);
        t2 = t2->next;
      }
      *t1 = (*t1)->next;
      return head;
    }
};

