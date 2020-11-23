/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 12ms 8.02% 8.6MB 100.00%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> anagramMappings(
      std::vector<int>& A, std::vector<int>& B) {
    std::vector<int> rslt(A.size(), 0);
    std::unordered_map<int, int> ump;
    for (int i = 0; i < B.size(); ++i)
      ump[B[i]] = i;
    for (int i = 0; i < A.size(); ++i)
      rslt[i] = ump[A[i]];
    return rslt;
  }
};

int main() {
  std::vector<int> A = {12, 28, 46, 32, 50};
  std::vector<int> B = {50, 12, 32, 46, 28};

  Solution sln;
  auto r = sln.anagramMappings(A, B);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
