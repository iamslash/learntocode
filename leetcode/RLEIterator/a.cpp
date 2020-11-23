/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // Time Limit Exceeded
// class RLEIterator {
//  private:
//   int m_i = 0, m_j = 0;
//   std::vector<int> m_A;
//  public:
//   RLEIterator(std::vector<int>& A) {
//     m_A = A;
//   }    
//   int next(int n) {
//     int r = -1;
//     while (m_i < m_A.size() && m_A[m_i] == 0)
//       m_i += 2;
//     while (m_i < m_A.size() && n-- > 0) {
//       // printf("A[%d]:%d A[%d]:%d\n", m_i, m_A[m_i], m_i+1, m_A[m_i+1]);
//       r = m_A[m_i+1];
//       if (--m_A[m_i] <= 0)
//         m_i += 2;
//     }
//     return m_i < m_A.size() ? r : -1;
//   }
// };


// i
// 3 8 0 9 2 5
//

// 4ms 99.11% 10.2MB 34.71%
// O(N) O(N)
class RLEIterator {
 private:
  // m_i: index of m_A[], m_j: index of m_A[m_i]: 
  int m_i = 0, m_j = 0;
  std::vector<int> m_A;
 public:
  RLEIterator(std::vector<int>& A) {
    m_A = A;
  }
  int next(int n) {
    while (m_i < m_A.size()) {
      if (m_j + n > m_A[m_i]) {
        n -= m_A[m_i] - m_j;
        m_j = 0;
        m_i += 2;
      } else {
        m_j += n;
        return m_A[m_i+1];
      }
    }
    return -1;
  }
};

int main() {

  std::vector<int> A = {3, 8, 0, 9, 2, 5};
  RLEIterator ri(A);
  printf("%d\n", ri.next(2));
  printf("%d\n", ri.next(1));
  printf("%d\n", ri.next(1));
  printf("%d\n", ri.next(2));
  
  return 0;
}
