// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void printsa(const std::string& H, const std::vector<int>& sa) {
  for (int i = 0; i < sa.size(); ++i) {
    printf("%s\n", H.c_str() + sa[i]);
  }
}

struct Comp {
  std::string m_h;
  std::vector<int> m_group;
  int m_t;
  explicit Comp(const std::string& h, const std::vector<int>& group, int t) {
    m_h = h;
    m_group = group;
    m_t = t;
  }
  bool operator() (int i, int j) {
    if (m_group[i] != m_group[j])
      return m_group[i] < m_group[j];
    // printf("[%2d] %2d %2d %-10s %-10s\n", m_t, i, j,
    //        m_h.c_str()+i, m_h.c_str()+j);
    return m_group[i+m_t] < m_group[j+m_t];
  }
};

// O(N(lgN)^2)
std::vector<int> makesa(const std::string& H) {
  int h = H.size();
  // sa, group, t
  std::vector<int> sa(h);
  std::iota(sa.begin(), sa.end(), 0);
  std::vector<int> group(h+1, -1);
  for (int i = 0; i < h; ++i)
    group[i] = H[i];
  int t = 1;

  while (true) {
    // printf("[%d] ---------------------------------------\n", t);

    // sort suffix array
    Comp c(H, group, t);
    std::sort(sa.begin(), sa.end(), c);
    // printf("[%d] =======================================\n", t);
    // Printsa(s, sa);

    // make new t
    t *= 2;
    // base condition
    if (t >= h)
      break;

    // make new group for 2t
    std::vector<int> group2(h + 1, -1);
    group2[sa[0]] = 0;
    for (int i = 1; i < h; ++i) {
      if (c(sa[i-1], sa[i]))
        group2[sa[i]] = group2[sa[i-1]] + 1;
      else
        group2[sa[i]] = group2[sa[i-1]];
    }
    group = group2;
  }

  return sa;
}

int main() {
  std::string h = "banana";
  auto r = makesa(h);
  printsa(h, r);
  return 0;
}
