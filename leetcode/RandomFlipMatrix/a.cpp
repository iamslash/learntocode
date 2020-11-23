/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <unordered_map>

//   h : 2, w: 3
//
//   r : 5
//   i : 1  
// m_n : 5
// ump : 1:5

// // 32ms 17.65% 
// class Solution {
//  private:
//   int m_N;
//   int m_w;
//   int m_n;
//   std::unordered_map<int, int> m_ump;
//  public:
//   Solution(int n_h, int n_w) {
//     m_N = n_h * n_w;
//     m_n = m_N;
//     m_w = n_w;
//   }
    
//   std::vector<int> flip() {
//     int i = std::rand() % m_n;
//     int rslt;
    
//     if (m_ump.count(i)) 
//       rslt = m_ump[i];
//     else 
//       rslt = i;

//     if (m_ump.count(m_n-1))
//       m_ump[i] = m_ump[m_n-1];
//     else
//       m_ump[i] = m_n-1;

//     --m_n;
    
//     return {rslt / m_w, rslt % m_w};
//   }
    
//   void reset() {
//     m_ump.clear();
//     m_n = m_N;
//   }
// };

//   i : 0
//   r : 1
//   n : 0
// ump : 0:0
//
//       0 3 2 1
// 16ms 98.04%
// O(1) O(N)
class Solution {
 public:
  int m_n, m_h, m_w;
  std::unordered_map<int, int> m_ump;
    
  Solution(int n_rows, int n_cols) {
    m_h = n_rows;
    m_w = n_cols;
    reset();
  }
    
  std::vector<int> flip() {
    int i = rand() % (m_n--);
    int r = m_ump.count(i) ? m_ump[i] : i;
    m_ump[i] = m_ump.count(m_n) ? m_ump[m_n] : m_n;
    return {r / m_w, r % m_w};
  }
    
  void reset() {
    m_ump.clear();
    m_n = m_h * m_w;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */

int main() {

  Solution sln(2, 2);
  for (int i = 0; i < 4; ++i) {
    auto v = sln.flip();
    printf("[%d, %d] ", v[0], v[1]);
  }
  sln.reset();
  
  return 0;
}
