// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define MAXN 987654321

std::vector<int> partial_sum(const std::vector<int>& v) {
  std::vector<int> r(v.size(), 0);
  r[0] = v[0];
  for (int i = 1; i < v.size(); ++i) {
    r[i] = r[i - 1] + v[i];
  }
  return r;
}

int close_psum_to_zero(std::vector<int>& psum) {
  int r = MAXN;

  std::sort(psum.begin(), psum.end());
  for (int i = 1; i < psum.size(); ++i) {
    r = std::min(r, std::abs(psum[i] - psum[i-1]));
  }

  return r;
}

int main() {
  std::vector<int> a = {-14, 7, 2, 3, -8, 4, -6, 8, 9, 11};
  std::vector<int> psum = partial_sum(a);

  printf("%d\n", close_psum_to_zero(psum));

  return 0;
}
