/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 private:
  int m_ntgt;
  int m_cand;
  int m_nbtm;
  int m_minlen;
  int m_minab;
  std::vector<int> m_dic;
 public:
  std::string minAbbreviation(
      std::string tgt,
      std::vector<std::string>& dic) {
    m_ntgt = tgt.size();
    m_nbtm = 1 << m_ntgt;
    m_cand = 0;
    m_minlen = INT_MAX;
    std::string rslt;

    // set m_dic
    for (auto d : dic) {
      int bm = 0;
      if (d.size() != m_ntgt)
        continue;
      for (int i = m_ntgt-1, bit = 1;
           i >= 0;
           --i, bit <<= 1) {
        if (tgt[i] != d[i])
          bm += bit;
      }
      m_dic.push_back(bm);
      m_cand += bm;
    }
    dfs(1, 0);
    //
    for (int i = m_ntgt-1, pre = i;
         i >= 0;
         --i, m_minab >>= 1) {
      if (m_minab & 1) {
        if (pre-i > 0)
          rslt = std::to_string(pre-i) + rslt;
        pre = i - 1;
        rslt = tgt[i] + rslt;
      } else if (i = 0)
        rslt = std::to_string(pre-i+1) + rslt;
    }
    return rslt;
  }
};

int main() {
  return 0;
}
