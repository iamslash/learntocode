/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <unordered_set>

// 32ms 97.10% 20.6MB 32.98%
// union-find
// O(NlgN) O(N)
class Solution {
 private:
  std::vector<int> m_parent;
  void merge(int x, int y) {
    m_parent[find(x)] = find(y);
  }
  int find(int x) {
    if (m_parent[x] == x)
      return x;
    return m_parent[x] = find(m_parent[x]);
  }
 public:
  int removeStones(std::vector<std::vector<int>>& S) {
    m_parent = std::vector<int>(20000);
    std::iota(m_parent.begin(), m_parent.end(), 0);

    for (auto &pt : S) 
      merge(pt[0], pt[1] + 10000);

    std::unordered_set<int> rootust;
    for (auto &pt : S)  
      rootust.insert(find(pt[0]));
    return S.size() - rootust.size();
  }
};

int main() {
  return 0;
}
