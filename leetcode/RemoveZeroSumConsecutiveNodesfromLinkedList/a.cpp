/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_map>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 12ms 85.35% 10.6MB 100.00%
// O(N) O(N)
class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* u) {
    // make dummy node
    ListNode d(0);
    d.next = u;
    std::unordered_map<int, ListNode*> sum2node = {{0, &d}};
    int sum = 0;
    while (u) {
      sum += u->val;
      if (!sum2node.count(sum)) {
        sum2node[sum] = u;
      } else {
        ListNode* v = sum2node[sum];
        ListNode* p = v;
        int lsum = sum;
        while (v != u) {
          v = v->next;
          lsum += v->val;
          if (v != u)
            sum2node.erase(lsum);
        }
        p->next = u->next;
      }
      u = u->next;
    }
    return d.next;
  }
};

int main() {
  return 0;
}
