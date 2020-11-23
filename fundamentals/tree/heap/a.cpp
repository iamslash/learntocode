/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // clumsy pop
// class MyHeap {
//  private:
//   std::vector<int> m_data;
//  public:
//   void push(int val) {
//     int u = m_data.size();
//     m_data.push_back(val);
//     while (u > 0) {
//       int p = (u-1)/2;
//       if (m_data[p] < m_data[u])
//         std::swap(m_data[p], m_data[u]);
//       else
//         break;
//       u = p;
//     }
//   }
//   int pop() {
//     if (m_data.empty())
//       return -1;
//     int n = m_data.size();
//     std::swap(m_data[0], m_data[n-1]);
//     int t = m_data.back();
//     m_data.pop_back();

//     int u = 0;
//     while (true) {
//       int l = u * 2 + 1;
//       int r = u * 2 + r;

//       // compare and swap
//       if (l >= n) {
//         break;
//       } else if (r >= n) {
//         if (m_data[u] >= m_data[l]) {
//           break;
//         } else {
//           std::swap(m_data[u], m_data[l]);
//           u = l;
//         }
//       } else {
//         if (m_data[u] >= std::max(m_data[l], m_data[r])) {
//           break;         
//         } else {
//           if (m_data[l] > m_data[r]) {
//             std::swap(m_data[l], m_data[u]);
//             u = l;
//           } else {
//             std::swap(m_data[r], m_data[u]);
//             u = r;
//           }
//         }
//       }      
//     }
//     return t;
//   }
// };

// fancy one
class MyHeap {
 private:
  std::vector<int> m_data;
 public:
  void push(int val) {
    int u = m_data.size();
    m_data.push_back(val);
    while (u > 0) {
      int p = (u-1)/2;
      if (m_data[p] < m_data[u])
        std::swap(m_data[p], m_data[u]);
      else
        break;
      u = p;
    }
  }
  int pop() {
    if (m_data.empty())
      return -1;
    int n = m_data.size();
    std::swap(m_data[0], m_data[n-1]);
    int t = m_data.back();
    m_data.pop_back();

    int u = 0;
    while (true) {
      int v = u;
      int l = u * 2 + 1;
      int r = u * 2 + r;

      // compare and swap
      if (l >= n)
        break;
      if (m_data[l] > m_data[v])
        v = l;
      if (r < n && m_data[r] > m_data[v])
        v = r;
      if (u == v)
        break;
      std::swap(m_data[u], m_data[v]);
      u = v;
    }
    return t;
  }
};


int main() {
  return 0;
}
