/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>

// queries = [
//   "FooBar",
//   "FooBarTest",
//   "FootBall",
//   "FrameBuffer",
//   "ForceFeedBack"]
// pattern = "FB"
//
// true,false,true,true,false

// queries = [
//     "FooBar",
//     "FooBarTest",
//     "FootBall",
//     "FrameBuffer",
//     "ForceFeedBack"
// pattern = "FoBa"
//
// [true,false,true,false,false]

// 4ms 69.39% 8.4MB 100.00%
// bruteforce
// O(QP) O(Q)
class Solution {
 private:
  bool isMatched(std::string q, std::string p) {
    int i = 0;
    for (char c : q) {
      if (i < p.size() && c == p[i])
        ++i;
      else if (c < 'a')
        return false;
    }
    return p.size() == i;
  }
 public:
  std::vector<bool> camelMatch(
      std::vector<std::string>& queries, std::string pattern) {
    std::vector<bool> ans;
    for (auto &q : queries)
      ans.push_back(isMatched(q, pattern));
    return ans;
  }
};

int main() {
  return 0;
}
