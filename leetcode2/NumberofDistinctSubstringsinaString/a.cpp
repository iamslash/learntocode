/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// // Time Limit Excceded
// // hash set
// // O(N^2) O(N)
// class Solution {
//  public:
//   int countDistinct(string s) {
//     int n = s.size(), ans = 0;
//     for (int j = 1; j <= n; ++j) {
//       unordered_set<string> ust;
//       for (int i = 0; i + j <= n; ++i) {
//         ust.insert(s.substr(i, j));
//       }
//       ans += ust.size();
//     }
//     return ans;
//   }
// };

// // Time Limit Exceeded
// // trie
// // O(N) O(N)
// class Node {
//  public:
//   vector<Node*> children = vector<Node*>(26, NULL);
// };
// class Solution {
//  public:
//   int countDistinct(string s) {
//     int ans = 0;
//     Node* root = new Node();
//     for (int i = 0; i < s.size(); ++i) {
//       Node* u = root;
//       for (int j = i; j < s.size(); ++j) {
//         int idx = s[j]-'a';
//         if (u->children[idx] == NULL) {
//           u->children[idx] = new Node();
//           ans++;
//         }
//         u = u->children[idx];
//       }
//     }
//     return ans;
//   }
// };


// 1600ms 100.00% 255.4MB 100.00%
// rolling hash
// O(N^2) O(N)
class Solution {
 public:
  int countDistinct(string s) {
    int64_t ans = 1, sHash = 0, base = 1, mod = 1000000009;
    for (int i = 0; i + 1 < s.size(); ++i) {
      sHash = (sHash * 26 + s[i]) % mod;
      base = base * 26 % mod;
      unordered_set<int> ust{(int)sHash};
      for (int64_t j = i + 1, jHash = sHash; j < s.size(); ++j) {
        jHash = (mod + jHash * 26 + s[j] - base * s[j - i - 1] % mod) % mod;
        ust.insert((int)jHash);
      }
      ans += ust.size();
    }
    return ans;
  }
};
