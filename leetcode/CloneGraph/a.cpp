/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/clone-graph/description/

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>

struct UndirectedGraphNode {
  int label;
  std::vector<UndirectedGraphNode*> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

    //    1
    //   / \
    //  /   \
    // 0 --- 2
    //      / \
    //      \_/

    //    1
    //   / \
    //  /   \
    // 0 ---2 
    //     / \
    //     \ /
//
// stck: 0
//
// O(U+V) O(U)
// 28ms 34.22%
class Solution {
 public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode* node) {
    if (node == NULL)
      return NULL;
    std::unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    mp[node] = new UndirectedGraphNode(node->label);
    std::stack<UndirectedGraphNode*> stck;
    stck.push(node);
    // dfs
    while (!stck.empty()) {
      auto u = stck.top(); stck.pop();
      for (auto v : u->neighbors) {
        if (!mp.count(v)) {
          mp[v] = new UndirectedGraphNode(v->label);
          stck.push(v);
        }
        mp[u]->neighbors.push_back(mp[v]);
      }
    }    
    return mp[node];
  }
};


int main() {
  UndirectedGraphNode* u = new UndirectedGraphNode(0);
  u->neighbors.push_back(new UndirectedGraphNode(1));
  
  Solution s;
  UndirectedGraphNode* r = s.cloneGraph(u);
  return 0;
}
