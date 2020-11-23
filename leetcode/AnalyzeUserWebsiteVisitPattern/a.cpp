/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>

// 88ms 32.42% 24.1MB 25.00%
// hash
class Solution {
public:
    std::vector<std::string> mostVisitedPattern(
        std::vector<std::string>& U,
        std::vector<int>& T,
        std::vector<std::string>& W) {
      // {user : {time : site}}
      std::unordered_map<
        std::string,
        std::map<int, std::string>> ump_history;
      // {3-seq : count of 3-seq}
      std::map<std::vector<std::string>, int> smp_cnts;
      int n = U.size();
      for (int i = 0; i < n; ++i)
        ump_history[U[i]][T[i]] = W[i];
      for (auto& pru : ump_history) {
        std::vector<std::string> v;
        auto& smp_timeline = pru.second; // time line
        for (auto& prt : smp_timeline)
          v.push_back(prt.second);
        std::set<std::vector<std::string>> seqs;
        for (int k = 0; k < v.size(); ++k)
          for (int j = 0; j < k; ++j)
            for (int i = 0; i < j; ++i)
              seqs.insert({v[i], v[j], v[k]});
        for (auto& seq : seqs)
          smp_cnts[seq]++;                      
      }
      auto ans = std::max_element(
          smp_cnts.begin(),
          smp_cnts.end(),
          [](const std::pair<std::vector<std::string>, int>& a,
             const std::pair<std::vector<std::string>, int>& b) {
            if (a.second == b.second)
              return a.first > b.first;
            return a.second < b.second;
          });
      return ans->first;
    }
};

int main() {
  return 0;
}
