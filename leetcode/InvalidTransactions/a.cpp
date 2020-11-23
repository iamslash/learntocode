/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

// "alice,20,800,mtv"

// 84ms 44.36% 20.9MB 100.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  std::vector<std::string> invalidTransactions(
      std::vector<std::string>& T) {
    std::unordered_set<std::string> ust_inval;
    std::unordered_map<
      std::string,
      std::vector<std::vector<std::string>>> ump_trnx;
    for (auto& s : T) {
      std::istringstream iss(s);
      std::vector<std::string> t(4, "");
      int i = 0;
      while (std::getline(iss, t[i++], ','))
        ;
      if (std::stoi(t[2]) > 1000)
        ust_inval.insert(s);
      for (auto& v : ump_trnx[t[0]]) {
        if ((v[3] != t[3]) &&
            std::abs(std::stoi(v[1]) - std::stoi(t[1])) <= 60) {
          ust_inval.insert(v[0] + "," + v[1] + "," +
                           v[2] + "," + v[3]);
          ust_inval.insert(s);
        }
      }
      ump_trnx[t[0]].push_back(
          {t[0], t[1], t[2], t[3]});
    }
    return std::vector<std::string>(ust_inval.begin(), ust_inval.end());
  }
};

int main() {
  return 0;
}
