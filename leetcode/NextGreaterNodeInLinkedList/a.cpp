/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

//       i
//  ans: 2 0 5 5 5
// stck: 7

// 212ms 81.68% 24.5MB 81.31%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> nextLargerNodes(ListNode *h) {
    std::vector<int> ans;
    std::stack<int> stck;
    while (h) {
      ans.push_back(h->val);
      h = h->next;
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
      int val = ans[i];
      while (stck.size() && stck.top() <= ans[i])
        stck.pop();
      ans[i] = stck.empty() ? 0 : stck.top();
      stck.push(val);
    }
    return ans;
  }
};

int main() {
  return 0;
}
