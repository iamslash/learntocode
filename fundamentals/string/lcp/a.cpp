// Copyright (C) 2019 by iamslash

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

int main() {
  std::string H = "banana";
  auto sa = makesa(H);
  printsa(H, sa);
  getlcp(H, sa[0], sa[0]);
  for (int i = 1; i < H.size(); ++i) {
    int lcp = getlcp(H, sa[i-1], sa[i]);
    printf("%d\n", lcp);
  }
  
  return 0;
}
