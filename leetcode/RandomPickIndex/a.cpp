/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cstdlib>

// // 88ms 57.51%
// class Solution {
//  private:
//   std::unordered_map<int, std::vector<int>> m_C; // value : idx
//  public:
//   Solution(std::vector<int> V) {
//     for (int i = 0; i < V.size(); ++i)
//       m_C[V[i]].push_back(i);
//   }
    
//   int pick(int num) {
//     int idx = rand() % m_C[num].size();
//     return m_C[num][idx];
//   }
// };

// 50ms 98.98%
class Solution {
 private:
  std::vector<int> m_V;
 public:
  Solution(std::vector<int> V) : m_V(V) {}
  int pick(int tgt) {
    unsigned int tgt_cnt = 0;
    int idx = 0;
    for (int i = 0; i < m_V.size(); ++i) {
      if (m_V[i] == tgt) {
        ++tgt_cnt;
        if (rand() % tgt_cnt == 0)
          idx = i;
      }
    }
    return idx;
  }
  
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
int main() {
  std::vector<int> V = {1, 2, 3, 3, 3};
  
  Solution sln(V);
  printf("%d\n", sln.pick(3));
  
  return 0;
}
