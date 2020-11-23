/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <map>

// // 180ms 58.85% 48.1MB 43.48%
// // only one topological sort
// // O(SV) O(N)
// // S: size of seqs
// // V: size of seq
// // N: size of org
// class Solution {
//  public:
//   bool sequenceReconstruction(std::vector<int>& org, std::vector<std::vector<int>>& seqs) {
//     int n = org.size();
//     std::unordered_map<int, std::unordered_set<int>> adj;
//     std::vector<int> indeg(n + 1, -1);
//     for (auto v : seqs) {
//       for (int i = 0; i < v.size(); i++) {
//         if(v[i] > n || v[i] < 0)
//           return false;
//         if(indeg[v[i]] == -1)
//           indeg[v[i]] = 0;
//         if(i + 1 < v.size() && adj[v[i]].insert(v[i + 1]).second) {
//           if(v[i + 1] > n || v[i + 1] < 0)
//             return false;
//           else
//             indeg[v[i + 1]] += indeg[v[i + 1]] < 0 ? 2 : 1;
//         }
//       }
//     }
//     for (int i = 0; i < n - 1; i++) {
//       if (indeg[org[i]] || !indeg[org[i + 1]]) {
//         return false;
//       } else {
//         for(auto x: adj[org[i]]) {
//           indeg[x]--;
//         }
//       }
//     }
//     return indeg[org.back()] == 0;
//   }
// };

// 84ms 86.05% 15.2MB 91.30%
// check position of org
// O(SV) O(N)
class Solution {
 public:
  bool sequenceReconstruction(std::vector<int>& org,
                              std::vector<std::vector<int>>& seqs) {
    if(seqs.empty())
      return false;
    
    // pos[i] : index of org[i]
    std::vector<int> pos(org.size() + 1);
    for(int i = 0; i < org.size(); ++i) {
      pos[org[i]] = i;
    }

    // linked[u] : linked (1) not linked (0)
    std::vector<char> linked(org.size() + 1, 0);
    int tolink = org.size() - 1; 
    bool dirty = false;  // at least once linked
    for (const auto& seq : seqs) {
      for (int i = 0; i < seq.size(); ++i) {
        dirty = true;
        if(seq[i] <= 0 || seq[i] > org.size())
          return false;
        if (i == 0)
          continue;
        int u = seq[i-1];
        int v = seq[i];
        if(pos[u] >= pos[v])
          return false;
        if(linked[u] == 0 && pos[u] + 1 == pos[v]) {
          linked[u] = 1;
          --tolink;
        }
      }
    }
    return tolink == 0 && dirty;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  // std::std::vector<int> org = {1, 2, 3};
  // std::std::vector<std::std::vector<int>> seqs = {
  //   {1, 2},
  //   {1, 3},
  //   {2, 3}
  // };
  // std::std::vector<int> org = {1, 2, 3};
  // std::std::vector<std::std::vector<int>> seqs = {
  //   {1, 2}
  // };
  // std::std::vector<int> org = {4, 1, 5, 2, 6, 3};
  // std::std::vector<std::std::vector<int>> seqs = {
  //   {5, 2, 6, 3},
  //   {4, 1, 5, 2}    
  // };
  // std::std::vector<int> org = {1, 2, 3, 4};
  // std::std::vector<std::std::vector<int>> seqs = {
  //   {1, 2, 3},
  //   {3, 4},
  //   {4, 3}
  // };
  // std::std::vector<int> org = {1};
  // std::std::vector<std::std::vector<int>> seqs = {
  //   {1}, {1}, {1}
  // };
  // std::std::vector<int> org = {1};
  // std::std::vector<std::std::vector<int>> seqs = {
  //   {}, {}
  // };
  std::vector<int> org = {1};
  std::vector<std::vector<int>> seqs = {
    {1,-9},{-9,-8},{-8,-9}
  };
  
  Solution sln;
  printb(sln.sequenceReconstruction(org, seqs));
  
  return 0;
}
