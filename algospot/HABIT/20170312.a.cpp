// Copyright (C) 2017 by iamslash

#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

int K;

void PrintSuffixArray(const std::string& s, const std::vector<int>& sa) {
  for (int i = 0; i < sa.size(); ++i) {
    printf("  [%2d] %-10s\n", i, s.c_str() + sa[i]);
  }
}

std::vector<int> GetSuffixArray(const std::string& s) {
  std::vector<int> r(s.size());
  for (int i = 0; i < s.size(); ++i) {
    r[i] = i;
  }
  // std::sort(r.begin(), r.end(), Comp(s));
  std::sort(r.begin(), r.end(),
            [s](int i, int j) -> bool {
              return strcmp(s.c_str()+i, s.c_str()+j) < 0;
            });
  return r;
}

int GetLcpCnt(const std::string& s, const std::vector<int>& sa, int i, int j) {
  int r = 0;
  while (i < s.size() && j < s.size() && s[i] == s[j]) {
    ++r;
    ++i;
    ++j;
  }
  // printf("    i: %2d j: %2d r: %2d\n", i, j, r);
  return r;
}

int Solve(const std::string& s) {
  int r = 0;

  std::vector<int> sa = GetSuffixArray(s);
  // PrintSuffixArray(s, sa);

  for (int i = 0; i + K <= sa.size(); ++i) {
    r = std::max(r, GetLcpCnt(s, sa, sa[i], sa[i + K - 1]));
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &K);
    char buf[5000];
    scanf("%s", buf);

    printf("%d\n", Solve(buf));
  }
}
