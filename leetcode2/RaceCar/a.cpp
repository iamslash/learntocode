/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <queue>

using namespace std;

// target: 3
// position: 0 1 3 3
//           A A R
//    speed: 1 2 4-1

// target: 6
// position: 0 1 3 7 7 6
//           A A A R   A
//    speed: 1 2 4 8-1-2 

// target: 5
//     step: 0 1 2 3 4 5 6 7
// position: 0 1 3 3 2 2 3 5
//    speed: 1 2 4-1-2 1 2 4
//           A A R A R A A

// 12ms 66.91% 7.8MB 64.50%
// BFS
// O(2^N) O(N)
struct node {
  double step, pos, speed;
};
class Solution {
 public:
  int racecar(int target) {
    queue<node> q;
    q.push({0, 0, 1});
    while (!q.empty()) {
      auto u = q.front(); q.pop();
      if (u.pos == target)
        return u.step;
      q.push({u.step + 1, u.pos + u.speed, 2*u.speed});
      if (u.speed > 0 && (u.pos + u.speed) > target) {
        q.push({u.step+1, u.pos, -1});
      } else if (u.speed <= 0 && (u.pos + u.speed) < target) {
        q.push({u.step+1, u.pos, 1});
      }
    }
    return 0;
  }
};

// 0ms 100.00% 6.1MB 98.07%
// recursive dynamic programming
// O(N) O(N)
class Solution {
  int C[10001];
 public:
  int racecar(int target) {
    // memo
    int& r = C[target];
    if (r != 0)
      return r;
    // base
    int n = floor(log2(target)) + 1;
    if (1 << n == target + 1)
      return r = n;
    // recursion
    r = racecar((1 << n) - 1 - target) + n + 1;
    for(int m = 0; m < n - 1; ++m)
      r = min(r,
              racecar(target - (1 << (n-1)) + (1 << m)) +
              n + m + 1);
    return r;
  }
};
