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

class TrieNode {
 public:
  TrieNode* next[2];
  TreeNode() {
    next[0] = nullptr;
    next[1] = nullptr;
  }
};
class Solution {
 private:
  TrieNode* buildTrie(vector<int>& nums) {
  }
  int dfs(TrieNode* root, int x, int m, int val, int height) {
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
