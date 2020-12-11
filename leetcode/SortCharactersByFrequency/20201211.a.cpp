/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>

// 20ms 30.67%
class Solution {
 public:
  std::string frequencySort(std::string s) {
    std::string rslt;
    std::unordered_map<char, int> mp;
    for (char c : s) {
      mp[c]++;
    }
    std::vector<std::pair<char, int>> V;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      V.push_back({it->first, it->second});
    }
    std::sort(V.begin(), V.end(), [](const std::pair<char, int>& lhs,
                                     const std::pair<char, int>& rhs){
                return lhs.second > rhs.second;
      });
    for (auto it = V.begin(); it != V.end(); ++it) {
      for (int i = 0; i < it->second; ++i)
        rslt += it->first;
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  // printf("%s\n", sln.frequencySort("tree").c_str());
  // printf("%s\n", sln.frequencySort("cccaaa").c_str());
  printf("%s\n", sln.frequencySort("Aabb").c_str());
  
  return 0;
}
