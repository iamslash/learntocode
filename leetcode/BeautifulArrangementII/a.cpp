/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 28ms 100.00% 9.9MB 30.00%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> constructArray(int n, int k) {
    std::vector<int> rslt;
    int i = 1, j = n;
    while (i <= j) {
      if (k > 1)
        rslt.push_back(k-- % 2 ? i++ : j--);
      else
        rslt.push_back(i++);                       
    }
    return rslt;
  }
};

int main() {

  Solution sln;
  // int n = 3, k = 1;
  // int n = 9, k = 5;
  int n = 9, k = 4;
  auto r = sln.constructArray(n, k);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
