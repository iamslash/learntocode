/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* n) : val(x), next(n) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// 1 2 3 4 5
//           p
//     q
// 1 2 3 4
//         p
//   q

//
// O(2^N) O(lgN)
// 28ms 17.18%
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* h) {
    // base condition
    if (h == NULL)
      return NULL;

    // split tree
    ListNode** q = &h;
    ListNode* p = h;
    ListNode* r = NULL;
    while (p) {
      p = p->next ? p->next->next : p->next;
      if (p)
        q = &(*q)->next;
    }
    TreeNode* rslt = new TreeNode((*q)->val);
    r = (*q)->next;
    (*q) = NULL;

    // recursion
    rslt->left = sortedListToBST(h);
    rslt->right = sortedListToBST(r);
    
    return rslt;
  }
};

void printt(TreeNode* t) {
  if (t == NULL) {
    printf("N ");
    return;
  }
  printt(t->left);
  printf("%d ", t->val);
  printt(t->right);
}

int main() {
  ListNode* h = new ListNode(-10, new ListNode(-3, new ListNode(0, new ListNode(5, new ListNode(9)))));

  Solution s;
  TreeNode* t = s.sortedListToBST(h);

  printt(t);
  printf("\n");
  
  return 0;
}
