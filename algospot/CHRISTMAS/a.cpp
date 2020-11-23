// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/CHRISTMAS

#include <cstdio>
#include <vector>

int N, K;

void PrintVInt(const std::vector<int>& v) {
  for (const int& i : v) {
    printf("%d ", i);
  }
  printf("\n");
}

// max counts of one order way
// use the form nC2
int Solve1(const std::vector<int>& remsofpsum) {
  int r = 0;

  std::vector<int> rems(K, 0);

  for (int i = 0; i <= N; ++i) {
    ++rems[remsofpsum[i]];
  }
  for (int i = 0; i < K; ++i) {
    r += (rems[i] * (rems[i] - 1) / 2) % 20091101;
  }
  // PrintVInt(rems);

  return r;
}

// it's very difficult to understand the problem.
// several order counts
// should give away all dolls per one order
int Solve2(const std::vector<int>& rpsum) {
  // r[i] : max order counts at i
  std::vector<int> r(rpsum.size(), 0);
  std::vector<int> prev(rpsum.size(), -1);
  //
  for (int i = 0; i < rpsum.size(); ++i) {
    //
    int loc = prev[rpsum[i]];
    if (loc >= 0)
      r[i] = std::max(r[i-1], r[loc] + 1);
    prev[rpsum[i]] = i;
  }
  return r.back();
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
      scanf("%d %d", &N, &K);
      std::vector<int> psum(N+1, 0);
      psum[0] = 0;
      for (int i = 0; i < N; ++i) {
        int n;
        scanf("%d", &n);
        psum[i+1] = (psum[i] + n) % K;
      }
      printf("%d %d\n", Solve1(psum), Solve2(psum));
    }

  return 0;
}

