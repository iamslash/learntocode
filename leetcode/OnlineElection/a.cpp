/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>

// P: 0 1  1  0  0  1  0
// T: 0 5 10 15 20 25 30

// 372ms 41.72% 79.9MB 29.80%
// q: O(lgN) O(N)
class TopVotedCandidate {
 private:
  // {time : lead person}
  std::map<int, int> m_leads;
 public:
  TopVotedCandidate(std::vector<int>& P,
                    std::vector<int>& T) {
    int n = P.size(), lead = -1;
    // {person : vote count}
    std::unordered_map<int, int> vote;
    for (int i = 0; i < n; ++i)
      m_leads[T[i]] = P[i];
    for (auto& pr : m_leads) {
      if (++vote[pr.second] >= vote[lead])
        lead = pr.second;
      m_leads[pr.first] = lead;
    }
  }

  int q(int t) {
    auto it = std::prev(m_leads.upper_bound(t));
    return it->second;
  }
};

int main() {
  return 0;
}
