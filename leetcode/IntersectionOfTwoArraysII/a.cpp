/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    std::vector<int> r(std::max(nums1.size(), nums2.size()));
    auto it = std::set_intersection(nums1.begin(), nums1.end(),
                                    nums2.begin(), nums2.end(),
                                    r.begin());
    r.resize(it - r.begin());
    return r;
  }
};

int main() {
  return 0;
}
