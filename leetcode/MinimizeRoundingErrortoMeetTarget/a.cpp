/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

// 4ms 81.92% 8.9MB 100.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  std::string minimizeError(std::vector<std::string>& P, int T) {
    std::vector<int> remains;
    int errs = 0;
    for (auto &pr : P) {
      int np = std::round(std::stof(pr) * 1000);
      int quo = np / 1000, rem = np % 1000;
      T -= quo;
      if (rem)
        remains.push_back(rem);
    }
    if (T < 0 || T > remains.size())
      return "-1";
    std::nth_element(remains.begin(),
                     remains.begin() + remains.size() - T,
                     remains.end());
    for (int rem : remains)
      errs += T++ < remains.size() ? rem : 1000 - rem;
    // for (int i = 0; i < remains.size(); ++i)
    //   errs += i < T - 1 ? remains[i] : 1000 - remains[i];
    char buf[16] = {0, };
    snprintf(buf, sizeof(buf), "%0.3f", double(errs / 1000.0));
    return buf;
  }
};

int main() {
  std::vector<std::string> P = {"0.700","2.800","4.900"};
  int T = 8;
  // std::vector<std::string> P = {"1.500","2.500","3.500"};
  // int T = 10;

  Solution sln;
  printf("%s\n", sln.minimizeError(P, T).c_str());
  
  return 0;
}
