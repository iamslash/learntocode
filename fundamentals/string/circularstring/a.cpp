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

std::string circularstring(const std::string& s) {
  std::string r;
  std::string s2 = s + s;
  std::vector<int> sa = makesa(s2);
  // printsa(s2, sa);

  for (int i = 0; i < sa.size(); ++i) {
    // printf("%d\n", i);
    if (sa[i] <= s.size()) {
      r = s2.substr(sa[i], s.size());
      break;
    }
  }

  return r;
}

int main() {
  // std::string H = "dakedavraava";
  std::string H = "davidfun";
  printf("%s\n", circularstring(H).c_str());
  return 0;
}
