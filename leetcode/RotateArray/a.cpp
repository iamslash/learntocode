/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 1,2,3,4,5,6,7
// 4,3,2,1,7,6,5
// 5,6,7,1,2,3,4 

class Solution {
public:
  void rotate(std::vector<int>& nums, int k) {
    if (nums.size() <= 1)
      return;
    int n = nums.size();
    k = (n-k%n)%n;
    std::reverse(nums.begin(), nums.begin()+k);
    std::reverse(nums.begin()+k, nums.end());
    std::reverse(nums.begin(), nums.end());      
  }
};

int N, K;

int main() {
  
  Solution s;
  scanf("%d %d", &N, &K);
  std::vector<int> v(N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &v[i]);
  
  s.rotate(v, K);
  for (int e : v) {
    printf("%d ", e);
  }
  printf("\n");
  return 0;
}
