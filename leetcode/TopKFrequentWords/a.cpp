/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>

// 24ms 70.59% 12.2MB 37.82%
// O(NlgN) O(N)
struct PqComp {
  bool operator()(const std::pair<int, std::string>& a,
                const std::pair<int, std::string>& b) {
    return a.first == b.first ?
        a.second > b.second :
        a.first < b.first;
  }
};

class Solution {
 public:
  std::vector<std::string> topKFrequent(
      std::vector<std::string>& W, int k) {
    std::priority_queue<std::pair<int, std::string>,
                        std::vector<std::pair<int, std::string>>,
                        PqComp> pq;
    std::map<std::string, int> smp;
    for (auto& s : W)
      smp[s]++;
    for (auto& pr : smp)
        pq.push({pr.second, pr.first});

    std::vector<std::string> r;
    while (!pq.empty() && r.size() < k) {
      auto pr = pq.top(); pq.pop();
      r.push_back(pr.second);
    }
    return r;
  }
};

int main() {

  std::vector<std::string> W = {
    "i",
    "love",
    "leetcode",
    "i",
    "love",
    "coding"
  };
  int k = 3;

  // std::vector<std::string> W = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
  // int k = 4;
  
  Solution sln;
  auto rslt = sln.topKFrequent(W, k);
  for (auto& s : rslt)
    printf("%s ", s.c_str());
  printf("\n");
  
  return 0;
}
