/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>

//      i 
// s: IVIV
// r: 4

// 24ms 24.07% 10.2MB 41.18%
// math
// O(N) O(1)
class Solution {
 public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> dic = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000},
    };
    int n = s.size(), ans = dic[s[n-1]];
    for (int i = n - 2; i >= 0 ; --i) {
      if (dic[s[i]] > dic[s[i+1]])
        ans -= dic[s[i]];
      else
        ans += dic[s[i]];
    }
    return ans;
  }
};

int main() {
  return 0;
}
