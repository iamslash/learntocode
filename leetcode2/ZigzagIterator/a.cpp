/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 99.20% 9.9MB 86.21%
// O(N) O(N)    
class ZigzagIterator {
 private:
  std::vector<int> m_vj;
  std::vector<int> m_vk;
  int m_j;
  int m_k;
  int m_i;
  
 public:
  ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2) {
    m_vj = v1;
    m_vk = v2;
    m_j = 0;
    m_k = 0;
    m_i = 0;
  }

  int next() {
    if ((m_k >= m_vk.size()) ||
        (!(m_i&1) && (m_j < m_vj.size()))) {
      m_i++;
      return m_vj[m_j++];
    }
    m_i++;
    return m_vk[m_k++];
  }

  bool hasNext() {
    int n = m_vj.size() + m_vk.size();
    // printf("%d %d\n", m_i, n);
    return m_i < n;
  }
};

int main() {

  // std::vector<int> v1 = {1, 2};
  // std::vector<int> v2 = {3, 4, 5, 6};
  std::vector<int> v1 = {1, 2};
  std::vector<int> v2 = {};
  int n = v1.size() + v2.size();
  ZigzagIterator zi(v1, v2);
  for (int i = 0; i < n; ++i) {
    printf("%s ", zi.hasNext() ? "true" : "false");      
    printf("%d\n", zi.next());
  }
  printf("%s\n", zi.hasNext() ? "true" : "false");      
    
  return 0;
}
