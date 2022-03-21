/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

// {3}
// {3, 1} {1}
// {3, 1, 2} {1, 2} {2}
// {3, 1, 2, 4} {1, 2, 4} {2, 4} {4}

// 3
// 1 1
// 1 1 2
// 1 1 2 4

//    A: 3 1 2 4
//             j
// stck: 2
//       1
//  cnt: 1
//  dot: 0
//  ans: 3

// 8ms 90.99% 13.5MB 82.79%
// using one stack
// O(N) O(N)
#define MOD 1000000007
class Solution {
 public:
  int sumSubarrayMins(std::vector<int>& A) {
    // {value : count}
    std::stack<std::pair<int, int>> stck;
    int ans = 0, dot = 0, n = A.size();
    for (int j = 0; j < n; ++j) {
      int cnt = 1;
      while (stck.size() && stck.top().first >= A[j]) {
        auto pr = stck.top(); stck.pop();
        cnt += pr.second;
        dot -= pr.first * pr.second;
      }
      stck.push({A[j], cnt});
      dot += A[j] * cnt;
      ans += dot;
      ans %= MOD;
    }
    return ans;
  }
};

int main() {

  std::vector<int> A = {3, 1, 2, 4};

  Solution sln;
  printf("%d\n", sln.sumSubarrayMins(A));
  
  return 0;
}
