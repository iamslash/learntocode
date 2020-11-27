/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

//                               i
//    T: 73 74 75 71 69 72 76 73
// stck: {6, 76} {7, 73}   
//  ans:  1  1  4  2  1  1  0  0

// 212ms 49.08%
class Solution {
 public:
  std::vector<int> dailyTemperatures(const std::vector<int>& T) {
    std::vector<int> rslt;
    if (T.empty())
      return rslt;

    std::stack<std::pair<int, int>> stck;
    stck.push({0, T[0]});
    rslt.resize(T.size(), 0);
    for (int i = 1; i < T.size(); ++i) {
      while (!stck.empty() && stck.top().second < T[i]) {
        const auto& spr = stck.top(); stck.pop();
        rslt[spr.first] = i - spr.first;
      }
      stck.push({i, T[i]});      
    }

    return rslt;
  }
};

int main() {
  std::vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution sln;
  auto rslt = sln.dailyTemperatures(T);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
