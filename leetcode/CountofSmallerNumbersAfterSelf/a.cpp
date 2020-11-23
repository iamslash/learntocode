// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

// //    i
// // V: 5 2 6 1
// // M: 1 2 6
// // R:   1 1 0
// class Solution {
//  public:
//   std::vector<int> countSmaller(std::vector<int>& V) {
//     if (V.empty())
//       return {};
//     std::vector<int> M;
//     std::vector<int> rslt(V.size(), 0);
//     for (int i = V.size() - 1; i >= 0; --i) {
//       int n = V[i];
//       auto it = std::lower_bound(M.begin(), M.end(), n);
//       rslt[i] = it - M.begin();
//       M.insert(it, n);
//       printf("i: %d, n: %d, R: %d, M.size: %d\n", i, n, rslt[i], M.size());
//     }
//     return rslt;
//   }
// };

// 32ms 52.42%
// class Solution {
//  public:
//   void solve(std::vector<int>& indices, int beg, int end,
//              std::vector<int>& counts, const std::vector<int>& V) {
//     int cnt = end - beg;
//     if (cnt > 1) {
//       // devide
//       int step = cnt / 2;
//       int mid = beg + step;
//       solve(indices, beg, mid, counts, V);
//       solve(indices, mid, end, counts, V);

//       // conquer
//       std::vector<int> mrgd;
//       mrgd.reserve(cnt);
//       int idx1 = beg;
//       int idx2 = mid;
//       int smallcnt = 0;
//       while ((idx1 < mid) || (idx2 < end)) {
//         int n1 = indices[idx1];
//         int n2 = indices[idx2];
//         if ((idx2 == end) ||
//             ((idx1 < mid) && (V[n1] <= V[n2]))) {
//           mrgd.push_back(n1);
//           counts[n1] += smallcnt;
//           ++idx1;
//         } else {
//           mrgd.push_back(n2);
//           ++smallcnt;
//           ++idx2;
//         }
//       }             
//       std::move(mrgd.begin(), mrgd.end(), indices.begin() + beg);
//     }
//   }
//   std::vector<int> countSmaller(std::vector<int>& V) {
//     if (V.empty())
//       return {};
//     int n = V.size();
//     std::vector<int> indices(n, 0);
//     std::vector<int> counts(n, 0);
//     std::iota(indices.begin(), indices.end(), 0);
//     solve(indices, 0, n, counts, V);
//     return counts;
//   }
// };

// 32ms 52.51%
struct BSTNode{
  int val;
  int cnt;
  BSTNode* left;
  BSTNode* right;
  explicit BSTNode(int x): val(x), cnt(0), left(NULL), right(NULL){}
};
class Solution {
public:
  std::vector<int> countSmaller(std::vector<int>& nums) {
    std::vector<int> rslt;
    std::vector<int> count;        
    std::vector<BSTNode*> nodes;
    
    for(int i = nums.size() - 1; i >= 0; --i){
      nodes.push_back(new BSTNode(nums[i]));
    }
    count.push_back(0);
    for(int i = 1 ; i < nodes.size(); ++i){
      int scnt = 0;
      bstInsert(nodes[0], nodes[i], scnt);
      count.push_back(scnt);      
    }      
    for(int i = nodes.size() - 1; i >= 0; --i){
      delete nodes[i];
      rslt.push_back(count[i]);           
    }
    return rslt;
  }
  void bstInsert(BSTNode* node, BSTNode* newnode, int & scnt){
    if(newnode->val <= node->val){      
      node->cnt++;
      if(node->left){
        bstInsert(node->left,newnode,scnt);
      }else{
        node->left = newnode;
      }
    }else{
      scnt += node->cnt + 1;
      if(node->right){
        bstInsert(node->right,newnode,scnt);
      }else{
        node->right = newnode;
      }
    }
  }
};

int main() {
  std::vector<int> V = {5, 2, 6, 1};

  Solution sln;
  auto rslt = sln.countSmaller(V);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");

  // std::vector<int> M = {1};
  // auto lit = std::lower_bound(M.begin(), M.end(), 6);
  // auto uit = std::upper_bound(M.begin(), M.end(), 6);
  // printf("begin: %d end: %d e-b: %d lit: %d uit: %d\n",
  //        M.begin(), M.end(), M.end()-M.begin(), lit, uit);
  // printf("*lit: %d, diff: %d\n", *lit, lit-M.begin());
  // printf("*uit: %d, diff: %d\n", *uit, uit-M.begin());
  
  return 0;
}
