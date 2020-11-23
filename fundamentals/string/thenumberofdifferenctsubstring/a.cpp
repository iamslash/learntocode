// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>
#include <numeric>

void printsa(const std::string& H, const std::vector<int>& sa) {
  for (int i = 0; i < sa.size(); ++i) {
    printf("%s\n", H.c_str() + sa[i]);
  }
}

std::vector<int> makesa(const std::string& H) {
  std::vector<int> sa(H.size());
  std::iota(sa.begin(), sa.end(), 0);
  std::sort(sa.begin(), sa.end(),
            [&H](int i, int j) -> bool {
              return strcmp(H.c_str()+i, H.c_str()+j) < 0;
            });
  return sa;
}

int getlcp(const std::string& H, int i, int j) {
  int h = H.size();
  int cnt = 0;
  while (i < h && j < h && H[i] == H[j]) {
    cnt++;
    i++;
    j++;
  }
  return cnt;
}

int solve(const std::string& H) {
  int h = H.size();
  std::vector<int> sa = makesa(H);
  int r = 0;
  for (int i = 0; i < sa.size(); ++i) {
    int lcp = 0;
    if (i > 0)
      lcp = getlcp(H, sa[i-1], sa[i]);
    r += (h - sa[i]) - lcp;
  }
  return r;
}

int main() {
  // std::string H = "banana";
  std::string H = "ababa";
  printf("%d\n", solve(H));
  return 0;
}
