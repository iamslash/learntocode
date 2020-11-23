/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>


// i = 3, set = {1000, 0000}, max = 1000
// i = 2, set = {1100, 1000, 0100, 0000}, max = 1100
// i = 1, set = {1110, 1010, 0110, 0010}, max = 1100
// i = 0, set = {1110, 1011, 0111, 0010}, max = 1100

// 14 11 7 2
//
//       i
// 1 1 1 0
// 1 0 1 1
// 0 1 1 1
// 0 0 1 0

// uset: 1110 1010 0110 0010
// mask: 1110
// rslt: 1100
//    t: 1110

// 60ms 46.47%
// class Solution {
//  public:
//   int findMaximumXOR(std::vector<int>& V) {
//     int rslt = 0, mask = 0;
//     for (int i = 31; i >= 0; --i) {
//       mask |= (1 << i);
//       std::unordered_set<int> ust;
//       for (int a : V)
//         ust.insert(a & mask);
//       int t = rslt | (1 << i);
//       for (int prf : ust) {
//         if (ust.count(t ^ prf)) {
//           rslt = t;
//           break;
//         }
//       }
//     }
//     return rslt;
//   }
// };

class TrieNode {
 public:
  TrieNode* next[2];
  TrieNode() {
    next[0] = NULL; next[1] = NULL;
  }
};

// 32ms 86.07%
class Solution {
 private:
  TrieNode* build(const std::vector<int>& V) {
    TrieNode* root = new TrieNode();
    TrieNode* u;
    int n = V.size();
    for (int i = 0; i < n; ++i) {
      int num = V[i];
      u = root;
      for (int j = 31; j >= 0; --j) {
        int k = ((num >> j) & 1);
        if (u->next[k] == NULL)
          u->next[k] = new TrieNode();
        u = u->next[k];
      }
    }
    return root;
  }
  int search(TrieNode* u, int num) {
    int rslt = 0;
    for (int i = 31; i >= 0; --i) {
      int idx = ((num >> i) & 1) ? 0: 1;
      if (u->next[idx]) {
        rslt <<= 1;
        rslt |= 1;
        u = u->next[idx];
      } else {
        rslt <<= 1;
        rslt |= 0;
        u = u->next[idx ^ 1];
      }
    }
    return rslt;
  }
 public:
  int findMaximumXOR(std::vector<int>& V) {
    int rslt = 0;
    TrieNode* root = build(V);
    for (int num : V)
      rslt = std::max(rslt, search(root, num));
    return rslt;
  }
  
};

int main() {
  std::vector<int> V = {3, 10, 5, 25, 2, 8};
  // std::vector<int> V = {1, 8, 16};
  
  Solution sln;
  printf("%d\n", sln.findMaximumXOR(V));
  
  return 0;
}
