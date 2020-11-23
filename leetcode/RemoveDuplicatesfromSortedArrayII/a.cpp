// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <cstdio>
#include <vector>

//         i
// 1 1 1 2 2 3
//       j
// 1 1 2 2 3
class Solution {
 public:
  int removeDuplicates(std::vector<int>& v) {
    int j = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (i < 2 || v[i] > v[j-1] || v[i] > v[j-2])
        v[j++] = v[i];
    }
    return j;
  }
};

int main() {
  std::vector<int> v = {1, 1, 1, 2, 2, 3};
  // std::vector<int> v = {0, 0, 1, 1, 1, 2, 3, 3};
  
  Solution s;
  printf("%d\n", s.removeDuplicates(v));
  for (int a : v) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
