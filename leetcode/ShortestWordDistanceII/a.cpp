/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// 48ms 97.19% 19.7MB 92.96%
// O(N) O(N)
class WordDistance {
 private:
  std::unordered_map<std::string, std::vector<int>> m_smp;
 public:
  WordDistance(std::vector<std::string>& W) {
    for (int i = 0; i < W.size(); ++i) {
      m_smp[W[i]].push_back(i);
    }
  }
    
  int shortest(std::string a, std::string b) {
    auto& va = m_smp[a];
    auto& vb = m_smp[b];
    auto i = va.cbegin();
    auto j = vb.cbegin();
    int d = INT_MAX;
    while (i != va.cend() && j != vb.cend()) {
      d = std::min(d, std::abs(*j - *i));
      if (*i < *j)
        ++i;
      else
        ++j;
    }
    return d;
  }
};

int main() {

  std::vector<std::string> W = {
    "practice", "makes", "perfect", "coding", "makes"
  };
  WordDistance wd(W);
  printf("%d\n", wd.shortest("coding", "practice"));
  printf("%d\n", wd.shortest("makes", "coding"));
  
  return 0;
}
