/* Copyright (C) 2019 by iamslash */

#include <cstdio>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 44ms 81.70% 14.6MB 61.85%
// O(N) O(1)
class Solution {
 public:
  int numComponents(ListNode* h, vector<int>& G) {
    std::unordered_set<int> ust(G.begin(), G.end());
    int cnt = 0;
    while (h) {
      if (ust.count(h->val) &&
          (!h->next || !ust.count(h->next->val)))
        ++cnt;
      h = h->next;
    }
    return cnt;
  }
};

int main() {
  return 0;
}
