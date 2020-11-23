/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

// // recursive way
// // 24ms 69.86%
// class Solution {
  
//  private:
//   std::vector<int> m_V;
//   std::vector<std::vector<int>> m_C;
//   bool solve(int i, int sum) {
//     // printf("%d %d\n", i, sum);
//     // base
//     if (sum == 0)
//       return true;
//     if (sum < 0 || i >= m_V.size())
//       return false;

//     // memoization
//     int& r = m_C[i][sum];
//     if (r != -1)
//       return r;

//     // recursion
//     r = solve(i+1, sum-m_V[i]) ||
//         solve(i+1, sum);
    
//     return r;
//   }
//  public:
//   bool canPartition(std::vector<int>& V) {
//     int sum  = std::accumulate(V.begin(), V.end(), 0, std::plus<int>());
//     int half = sum / 2;

//     if (sum % 2 != 0)
//       return false;
        
//     m_V = V;
    
//     m_C.resize(V.size(), std::vector<int>(half+1, -1));
//     return solve(0, half);
//   }
// };

void printvv(const std::vector<std::vector<bool>>& C) {
  for (const auto& l : C) {
    for (const auto& b : l) {
      printf("%c ", b ? 't' : '.');
    }
    printf("\n");
  }
}

// // iterative way
// // 64ms 31.66%
// class Solution {
//  public:
//   bool canPartition(const std::vector<int>& V) {
//     int sum = std::accumulate(V.begin(), V.end(), 0, std::plus<int>());
//     if (sum & 1)
//       return false;
//     int haf = sum >> 1;

//     std::vector<bool> C(haf+1, false);
//     C[0] = true;
//     for (int num : V) {
//       for (int i = haf; i >= num; --i) {
//         if (C[i-num] == true)
//           C[i] = true;
//       }
//     }
//     return C[haf];
//   }
// };

// backtracking with pruning
// 4ms 96.17%
class Solution {
 private:
  bool solve(const std::vector<int>& V, int start, int haf) {
    // base
    if (haf == 0)
      return true;
    for (int i = start; i < V.size(); ++i) {
      if (V[i] > haf)
        continue;
      if (solve(V, i+1, haf-V[i]))
        return true;
      while (i+1 < V.size() && V[i] == V[i+1])
        ++i;
    }
    return false;
  }
  
 public:
  bool canPartition(std::vector<int>& V) {
    int sum = std::accumulate(V.begin(), V.end(), 0, std::plus<int>());
    if (sum & 1)
      return false;
    int haf = sum >> 1;
    std::sort(V.begin(), V.end(), std::greater<int>());
    return solve(V, 0, haf);    
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  // std::vector<int> V = {1, 5, 11, 5};
  // std::vector<int> V = {1, 2, 3, 5};
  // std::vector<int> V = {2, 2, 2};
  std::vector<int> V = {2, 2, 3, 5};

  Solution sln;
  printb(sln.canPartition(V));
  
  return 0;
}
