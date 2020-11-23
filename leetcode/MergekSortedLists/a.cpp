/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/117/linked-list/839/

#include <cstdio>
#include <vector>
#include <queue>

// O(NlgN) O(N)
// 16ms 99.98%
struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(NULL) {}
  explicit ListNode(int x, ListNode* p) : val(x), next(p) {}
};

#include <iostream>
static int _x=[](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}();
struct MyCmp {
  bool operator()(const ListNode* lhs, const ListNode* rhs) {
    return lhs->val > rhs->val;
  }
};
// bool mycmp (const ListNode* lhs, const ListNode* rhs) {
//   return lhs->val > rhs->val;
// }
class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& v) {
    ListNode* rh = NULL;
    ListNode* ri = NULL;
    
    std::priority_queue<ListNode*, std::vector<ListNode*>, MyCmp> pq;
    // std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(mycmp)> pq(mycmp);
    for (int i = 0; i < v.size(); ++i)
      if (v[i])
        pq.push(v[i]);
    
    while (!pq.empty()) {
      ListNode* p = pq.top(); pq.pop();
      // printf("%d ", p->val);
      if (rh == NULL) {
        rh = ri = p;
      } else {
        ri = ri->next = p;
      }
      if (p->next)
        pq.push(p->next);
    }
    // printf("\n");
    
    return rh;
  }
};

int main() {
  ListNode* p0 = new ListNode(1,
                              new ListNode(4,
                                           new ListNode(5)));
  ListNode* p1 = new ListNode(1,
                              new ListNode(3,
                                           new ListNode(4)));
  ListNode* p2 = new ListNode(2,
                              new ListNode(6));
  std::vector<ListNode*> v;
  v.push_back(p0);
  v.push_back(p1);
  v.push_back(p2);
  
  Solution s;
  ListNode* p = s.mergeKLists(v);

  while (p) {
    printf("%d ", p->val);    
    p = p->next;
  }
  printf("\n");
  
  return 0;
}
