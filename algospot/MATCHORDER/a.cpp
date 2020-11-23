// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MATCHORDER
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

int N;
std::vector<int> RUS;
std::vector<int> KOR;
std::multiset<int> KORSET;

// return max win cnt
int solve() {
  int r = 0;
  // sort
  std::sort(RUS.begin(), RUS.end());
  for (int i = 0; i < KOR.size(); ++i)
    KORSET.insert(KOR[i]);
  for (int i = RUS.size() - 1; i >= 0; --i) {
    if (*KORSET.rbegin() < RUS[i]) {  // use kor min cand
      KORSET.erase(KORSET.begin());
    } else {  // use next big cand
      KORSET.erase(KORSET.lower_bound(RUS[i]));
      r++;
    }
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    RUS.resize(N);
    KOR.resize(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &RUS[i]);
    for (int i = 0; i < N; ++i)
      scanf("%d", &KOR[i]);
    printf("%d\n", solve());
  }
  return 0;
}


