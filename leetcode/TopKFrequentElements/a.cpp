/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/799/

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::vector<int> r;
    std::map<int, int> m;
    std::vector<std::pair<int, int>> v;
    // gether count
    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(nums[i]) != m.end())
        m[nums[i]]++;
      else
        m[nums[i]]=1;
    }
    for (const auto& e : m) {
      v.push_back(e);
    }
    // sort it by count
    std::sort(v.begin(), v.end(), [](const std::pair<int, int>& a,
                                     const std::pair<int, int>& b) {
                return a.second > b.second;
      });
    
    for (const auto& e : v) {
      r.push_back(e.first);
      if (--k ==0)
        break;
    }
    
    return r;
  }
};

int main() {

  std::vector<int> v = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3};
  int k = 2;
  
  Solution s;
  std::vector<int> r = s.topKFrequent(v, k);
  for (int e : r) {
    printf("%d ", e);
  }
  printf("\n");
  return 0;
}
