/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 20ms 40.58%
// O(NlgN) O(N)
class Solution {
 private:
  int str2min(std::string s) {
    int h = std::stoi(s.substr(0, 2));
    int m = std::stoi(s.substr(3, 2));
    return h * 60 + m;
  }
  int getDiff(int a, int b) {
    if (a > b)
      std::swap(a, b);
    int e = 1439; // 23 * 60 + 59
    return std::min(b - a, a + e - b + 1);
  }
 public:
  int findMinDifference(const std::vector<std::string>& T) {
    int n = T.size();
    std::vector<int> V;
    for (auto s : T)
      V.push_back(str2min(s));
    std::sort(V.begin(), V.end());
    int rslt = V.back();
    for (int i = 0; i < V.size(); ++i) {
      rslt = std::min(rslt, getDiff(V[i], V[(i+1)%n]));
    }
    return rslt;
  }
};

int main() {
  std::vector<std::string> T = {"23:59","00:00"};
  Solution sln;
  printf("%d\n", sln.findMinDifference(T));
  
  return 0;
}
