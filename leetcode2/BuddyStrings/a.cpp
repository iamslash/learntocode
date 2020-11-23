/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <set>
#include <string>
#include <vector>

// 4ms 98.43% 6.8MB 100.00%
// linear traversal
// O(N) O(N)
class Solution {
 public:
  bool buddyStrings(std::string a, std::string b) {
    if (a.size() != b.size())
      return false;
    if (a == b && std::set<char>(a.begin(), a.end()).size() < a.size())
      return true;
    std::vector<int> diff;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i])
        diff.push_back(i);
      if (diff.size() > 2)
        return false;
    }
    return diff.size() == 2 &&
        a[diff[0]] == b[diff[1]] &&
        a[diff[1]] == b[diff[0]];
  }
};

int main() {
  return 0;
}
