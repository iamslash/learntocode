/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <cstdlib>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* n) :
      val(x), next(n) {}
};

// https://www.youtube.com/watch?v=A1iwzSew5QY
// 28ms 88.22%
class Solution {
 private:
  ListNode* m_head;
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* h) {
    m_head = h;
  }
    
  /** Returns a random node's value. */
  int getRandom() {
    int rslt = m_head->val;
    ListNode* p = m_head->next;
    int i = 2;
    while (p) {
      int j = std::rand() % i;
      if (j == 0)
        rslt = p->val;
      ++i;
      p = p->next;
    }
    return rslt;
  }
};

// // 40ms 39.96%
// class Solution {
//  private:
//   std::vector<ListNode*> m_nodes;
//  public:
//   Solution(ListNode* head) {
//     do {
//       m_nodes.push_back(head);
//     } while (head = head->next);
//   }
//   int getRandom() {
//     return m_nodes[rand() % m_nodes.size()]->val;
//   }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main() {
  ListNode* h = new ListNode(1);
  h->next = new ListNode(2);
  h->next->next = new ListNode(3);

  Solution sln(h);
  printf("%d\n", sln.getRandom());
  
  return 0;
}
