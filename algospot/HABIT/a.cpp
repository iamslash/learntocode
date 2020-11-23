// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

int K;

std::vector<int> get_sa(const std::string& s) {
  std::vector<int> r(s.size());
  for (int i = 0; i < s.size(); ++i)
    r[i] = i;
  std::sort(r.begin(), r.end(),
            [s](int i, int j)->bool {
              return strcmp(s.substr(i).c_str(),
                            s.substr(j).c_str()) < 0;
            });
  return r;
}

int get_common_prefix(const std::string& a, const std::string& b) {
  int i = 0, j = 0, k = 0;

  while (i < a.size() && j < b.size() && a[i] == b[j]) {
    ++i;
    ++j;
    ++k;
  }

  return k;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &K);
    char buf[4096];
    scanf("%s", buf);
    std::string s = buf;
    std::vector<int> sa = get_sa(s);

    int r = 0;
    for (int i = 0; i + K - 1 < s.size(); ++i) {
      std::string a = s.substr(sa[i]);
      std::string b = s.substr(sa[i+K-1]);
      r = std::max(r, get_common_prefix(a, b));
    }

    printf("%d\n", r);
  }

  return 0;
}





