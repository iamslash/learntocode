/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;


//    nums: 0 1 2 3 4
// queries: 3,1 1,2 5,6
//     ans:   3   3   7

// // Time Limit Excceded
// // brute force
// // O(N^2) O(N)
// class Solution {
//  public:
//   vector<int> maximizeXor(vector<int>& nums,
//                           vector<vector<int>>& queries) {    
//     vector<int> ans(queries.size(), -1);
//     for (int i = 0; i < queries.size(); ++i) {
//       auto& q = queries[i];
//       int maxXor = -1;
//       for (int num : nums) {
//         if (num <= q[1]) {
//           maxXor = max(maxXor, num ^ q[0]);
//         }
//       }
//       if (maxXor >= 0) {
//         ans[i] = maxXor;
//       }
//     }
//     return ans;
//   }
// };

// 812ms 70.30% 212.2MB 22.13%
// trie
// O(N) O(N)
class TrieNode {
 public:
  TrieNode* next[2];
  TrieNode() {
    next[0] = nullptr;
    next[1] = nullptr;
  };
};
class Solution {
 private:
  TrieNode* buildTrie(vector<int>& nums) {
    TrieNode* root = new TrieNode();
    TrieNode* p;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      p = root;
      for (int j = 31; j >= 0; j--) {
        int idx = ((num >> j) & 1);
        if (p->next[idx] == nullptr) {
          p->next[idx] = new TrieNode();
        }
        p = p->next[idx];
      }
    }
    return root;
  }
  int dfs(TrieNode* u, int x, int limit, int val, int height) {
    // base
    if (val > limit)
      return -1;
    if (height == -1)
      return x ^ val;
    int bitX = (x >> height) & 1;
    // recursion
    if (u->next[1-bitX] != nullptr) {
      int v = dfs(u->next[1-bitX], x, limit,
                  (val | ((1-bitX) << height)), height-1);
      if (v >= 0)
        return v;
    }
    if (u->next[bitX] != nullptr) {
      int v = dfs(u->next[bitX], x, limit,
                  (val | (bitX << height)), height-1);
      if (v >= 0)
        return v;
    }
    return -1;
  }
 public:
  vector<int> maximizeXor(vector<int>& nums,
                          vector<vector<int>>& queries) {
    vector<int> ans;
    TrieNode* root = buildTrie(nums);
    for (const vector<int>& q : queries) {
      ans.push_back(dfs(root, q[0], q[1], 0, 31));
    }
    return ans;    
  }
};
