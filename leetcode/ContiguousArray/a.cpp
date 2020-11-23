/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 96ms 70.66%
// O(N) O(N)
class Solution {
 public:
  int findMaxLength(std::vector<int>& V) {
    int cnt = 0;
    int rst = 0;    
    std::unordered_map<int, int> ump;  // count : index
    ump[0] = 0;
    for (int i = 1; i <= V.size(); ++i) {
      cnt = V[i-1] == 0 ? cnt - 1 : cnt + 1;
      if (ump.count(cnt) > 0)
        rst = std::max(rst, i - ump[cnt]);
      else
        ump[cnt] = i;
      // printf("i: %d, cnt: %d\n", i, cnt);
    }
    return rst;
  }
};

int main() {
  // std::vector<int> V = {0, 1};
  std::vector<int> V = {0, 0, 0, 0, 1, 1};

  Solution sln;
  printf("%d\n", sln.findMaxLength(V));
  
  return 0;
}
