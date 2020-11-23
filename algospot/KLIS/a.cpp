// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

const int MAX_INT = 2000000001;
int N, K;
std::vector<int> S;
int CACHE_CNT[501];
int CACHE_LEN[501];

int lis(int start) {
  int& r = CACHE_LEN[start + 1];
  if (r !=  -1)
    return r;
  r = 1;
  for (int next = start + 1; next < N; ++next) {
    if (start == -1 || S[start] < S[next]) {
      r = std::max(r, lis(next) + 1);
    }
  }
  return r;
}

// idx : 0 1 2 3 4
// S   : 1 5 4 3 2
// lis : 2 1 1 1 1
// cnt : 4 1 1 1 1
int count(int start) {
  if (lis(start) == 1)
    return 1;
  int& r = CACHE_CNT[start + 1];
  if (r != -1)
    return r;
  r = 0;
  for (int next = start + 1; next < N; ++next) {
    if ((start == -1 || S[start] < S[next]) &&
        lis(start) == lis(next) + 1) {
      r += std::min<int64_t>(MAX_INT, (int64_t)r + count(next));
    }
  }

  return r;
}

// idx : -1 0 1 2 3 4
// S   :    1 5 4 3 2
// lis :  3 2 1 1 1 1
// cnt :  4 4 1 1 1 1

// start : -1
// skip : 1
void solve(int start, int skip, std::vector<int>& v) {
  if (start != -1)
    v.push_back(S[start]);
  // S[i], i
  std::vector<std::pair<int, int> > followers;
  for (int next = start + 1; next < N; ++next) {
    if ((start == -1 || S[start] < S[next]) &&
        lis(start) == lis(next) + 1) {
      followers.push_back(std::make_pair(S[next], next));
    }
  }
  std::sort(followers.begin(), followers.end());
  for (int i = 0; i < followers.size(); ++i) {
    int idx = followers[i].second;
    int cnt = count(idx);
    if (cnt <= skip) {
      skip -= cnt;
    } else {
      solve(idx, skip, v);
      break;
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 501; ++i) {
      CACHE_LEN[i] = -1;
      CACHE_CNT[i] = -1;
    }
    scanf("%d %d", &N, &K);
    S.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &S[i]);
    }
    std::vector<int> v;
    solve(-1, K-1, v);
    printf("%lu\n", v.size());
    for (int i = 0; i < v.size(); ++i)
      printf("%d ", v[i]);
    printf("\n");
  }
  return 0;
}
