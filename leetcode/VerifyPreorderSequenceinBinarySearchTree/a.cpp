/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <stack>

 //     5
 //    / \
 //   2   6
 //  / \
 // 1   3

// 2 1 3

// // 40ms 88.62% 10.8MB 31.25%
// // recursive way
// // O(N) O(N)
// class Solution {
//  private:
//   int m_i;
//   void solve(std::vector<int>& V, int lo, int hi) {
//     // base condition
//     if (m_i == V.size() || V[m_i] < lo || V[m_i] > hi)
//       return;
//     int mi = V[m_i++];
//     solve(V, lo, mi - 1);
//     solve(V, mi + 1, hi);
//   }
//  public:
//   bool verifyPreorder(std::vector<int>& V) {
//     m_i = 0;
//     solve(V, INT_MIN, INT_MAX);
//     return m_i == V.size();
//   }
// };

// lo: 2
//     i
//   3 3 1
//   j

// // 40ms 88.62% 10.1MB 91.67%
// // iterative way
// // O(N) O(1)
// class Solution {
//  public:
//   bool verifyPreorder(std::vector<int>& V) {
//     if (V.empty())
//       return true;
//     int n = V.size();
//     int lo = INT_MIN;
//     int j = -1;
//     for (int i = 0; i < n; ++i) {
//       if (V[i] <= lo)
//         return false;
//       while (j >= 0 && V[i] > V[j]) {
//         lo = V[j];
//         j--;
//       }
//       V[++j] = V[i];
//     }
//     return true;
//   }
// };

//        i
// V: 2 1 3
// s: 3

//        i
// V: 2 3 1
// s: 3
// l: 2

// 44ms 72.97% 10.6MB 58.33%
// stack
// O(N) O(N)
class Solution {
 public:
  bool verifyPreorder(std::vector<int>& V) {
    std::stack<int> stck;
    int lowbnd = INT_MIN;
    for (int i = 0; i < V.size(); ++i) {
      if (stck.empty() || V[i] < V[i-1]) {
        if (V[i] <= lowbnd)
          return false;
        stck.push(V[i]);
      } else {
        while (!stck.empty() && stck.top() < V[i]) {
          lowbnd = stck.top(); stck.pop();
        }
        stck.push(V[i]);
      }
    }
    return true;
  }
};

int main() {
  return 0;
}

