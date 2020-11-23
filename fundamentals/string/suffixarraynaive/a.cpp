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
  int h = H.size();
  std::vector<int> sa(h);
  std::iota(sa.begin(), sa.end(), 0);
  std::sort(sa.begin(), sa.end(),
            [&H](int i, int j) -> bool {
              return strcmp(H.c_str()+i, H.c_str()+j) < 0;
            });
  return sa;
}

int main() {
  std::string h = "banana";
  auto r = makesa(h);
  printsa(h, r);
  return 0;
}
