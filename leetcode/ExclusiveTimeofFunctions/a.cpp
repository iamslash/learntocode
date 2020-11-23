/* Copyrigh t (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <sstream>

// 68ms 1.60%
// 9.4MB 0.75%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> exclusiveTime(int n, std::vector<std::string>& L) {
    std::vector<int> rslt(n, 0);
    std::stack<std::pair<int, int>> stck;  // id, start
    for (const auto& s : L) {
      std::string t;
      std::istringstream iss(s);
      std::getline(iss, t, ':');
      int idx = std::stoi(t);
      std::getline(iss, t, ':');
      std::string act = t;      
      std::getline(iss, t, ':');
      int ts = std::stoi(t);  // time stamp
      // printf("%d %s %d\n", idx, act.c_str(), ti);

      if (act == "start") {
        stck.push({idx, ts});
      } else {
        auto pr = stck.top(); stck.pop();
        int dtime = ts - pr.second + 1;
        rslt[pr.first] += dtime;
        if (!stck.empty())
          rslt[stck.top().first] -= dtime;
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<std::string> logs = {
    "0:start:0",
    "1:start:2",
    "2:start:3",
    "2:end:4",
    "1:end:5",
    "0:end:6"
  };
  // std::vector<std::string> logs = {
  //   "0:start:0",
  //   "0:start:2",
  //   "0:end:5",
  //   "0:start:6",
  //   "0:end:6",
  //   "0:end:7"
  // };
  int n = 3;

  Solution sln;
  auto r = sln.exclusiveTime(n, logs);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
