/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

// // 20ms 36.14% 8.3MB 92.88%
// // floyd's tortoise and hare algorithm
// // O(N) O(1)
// class Solution {
//  private:
//   int go(std::vector<int>& V, int i) {
//     int n = V.size();
//     int j = i + V[i];
//     int r = j >= 0 ? j % n :
//         j % n == 0 ? 0 : j % n + n;
//     return r;                         
//   }
//  public:
//   bool circularArrayLoop(std::vector<int>& V) {
//     int n = V.size();
//     if (n <= 1)
//       return false;
//     for (int i = 0; i < n; ++i) {
//       int slow = i;
//       int fast = go(V, slow);
//       while (V[slow] * V[fast] > 0 &&
//              V[slow] * V[go(V, fast)] > 0) {
//         if (slow == fast) {
//           // single loop
//           if (slow == go(V, slow))
//             break;
//           else
//             return true;
//         }
//         slow = go(V, slow);
//         fast = go(V, go(V, fast));
//       }
//     }
//     return false;
//   }
// };

// 4ms 93.99% 8.9MB 22.43%
// O(N) O(N)
class Solution {
 public:
  bool circularArrayLoop(std::vector<int>& V) {
    int n = V.size();
    std::vector<bool> seen(n, false);
    for (int i = 0; i < n; ++i) {
      if (seen[i])
        continue;
      seen[i] = true;
      std::unordered_set<int> ust;
      int cur = i;
      while (true) {
        int nxt = (cur + V[cur] % n + n) % n;
        if (nxt == cur || V[cur] * V[nxt] < 0)
          break;
        if (ust.count(nxt))
          return true;
        ust.insert(cur);
        cur = nxt;
        seen[nxt] = true;
      }
    }
    return false;
  }
};

int main() {
  // std::vector<int> V = {2, -1, 1, 2, 2};
  // std::vector<int> V = {-1, 2};
  // std::vector<int> V = {-2, 1, -1, -2, -2};
  // std::vector<int> V = {3, 1, 2};
  // std::vector<int> V = {1, 2, 3, 4, 5};
  // std::vector<int> V = {-2, -3, -9};
  std::vector<int> V = {-1, -1, -1};
  Solution sln;
  printb(sln.circularArrayLoop(V));

  // printf("%d %d %d %d\n", go(V, 0), go(V, 1), go(V, 2), go(V, 3));

  return 0;
}
