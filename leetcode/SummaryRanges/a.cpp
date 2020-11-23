// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <string>

//           f
//           t
// 0 1 2 4 5 7 -1
// 0ms 100%
class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int>& V) {
    std::vector<std::string> rslt;
    if (V.empty())
      return rslt;

    V.push_back(-1);
    int fr = V[0];
    int to = V[0];
    for (int i = 0; i < V.size() - 1; ++i) {
      if (to + 1 == V[i + 1]) {
        to++;
      } else {
        if (fr == to) {
          rslt.push_back(std::to_string(fr));
        } else {
          rslt.push_back(std::to_string(fr) + "->" +
                         std::to_string(to));
        }
        fr = to = V[i + 1];
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<int> V0 = {0, 1, 2, 4, 5, 7};
  std::vector<int> V1 = {0, 2, 3, 4, 6, 8, 9};

  Solution sln;
  auto rslt = sln.summaryRanges(V1);
  for (const auto& s : rslt) {
    printf("%s\n", s.c_str());
  }
  return 0;
}
