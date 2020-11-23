/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 2 1 4 3

// 3 1 2 5 4


//   N: 4
// ans: 1 3 2 4
// tmp:

// 8ms 91.27% 9.3MB 59.67%
// O(N^2) O(N)
class Solution {
 public:
  std::vector<int> beautifulArray(int N) {
    std::vector<int> ans = {1};
    while (ans.size() < N) {
      std::vector<int> tmp;
      for (int i : ans) {
        if (i * 2 - 1 <= N)
          tmp.push_back(i * 2 - 1);
      }
      for (int i : ans) {
        if (i * 2 <= N)
          tmp.push_back(i * 2);
      }
      ans = tmp;
    }
    return ans;
  }
};

int main() {

  Solution sln;
  auto r = sln.beautifulArray(10);
  for (int a : r)
    printf("%d ", a);
  printf("\n");

  return 0;
}
