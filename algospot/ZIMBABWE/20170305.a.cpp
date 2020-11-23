// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/ZIMBABWE

#include <cstdio>
#include <string>

const int MOD = 1000000007;

std::string E;
std::string DIGITS;
int N, M;
// CACHE[i][j][j] : taken, mod, less
int CACHE[1<<14][20][2];

void print_indent(int indent) {
  for (int i = 0; i < indent; ++i)
    printf("  ");
}

int solve(int idx, int taken, int mod, int less) {
  print_indent(idx);
  printf("%d %d %d %d\n", idx, taken, mod, less);
  // base condition
  if (idx == N) {
    int r = (less && mod == 0) ? 1 : 0;
    print_indent(idx);
    printf(".%d\n", r);
    return r;
  }
  // memoization
  int& r = CACHE[taken][mod][less];
  if (r != -1) {
    print_indent(idx);
    printf(";%d\n", r);
    return r;
  }
  // recursion
  r = 0;
  for (int next = 0; next < N; ++next) {
    // already used???
    if ((taken & (1 << (next))) == 1)
      continue;
    // past price should be lesser than current price
    if (!less && E[idx] < DIGITS[next])
      continue;
    // consider same digit just once
    if (next > 0 && DIGITS[next-1] == DIGITS[next] &&
        (taken & (1 << (next-1))) == 0)
      continue;
    int next_taken = taken | (1 << next);
    int next_mod = (mod * 10 + DIGITS[next] - '0') % M;
    int next_less = less || E[idx] > DIGITS[next];
    r += solve(idx + 1, next_taken, next_mod, next_less);
    r %= MOD;
  }
  print_indent(idx);
  printf(".%d\n", r);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < (1<<14); ++i) {
      for (int j = 0; j < 20; ++j) {
        for (int k = 0; k < 2; ++k) {
          CACHE[i][j][k] = -1;
        }
      }
    }
    char buf[32];
    scanf("%s %d", buf, &M);
    E = buf;
    DIGITS = buf;
    N = E.size();
    std::sort(DIGITS.begin(), DIGITS.end());
    printf("%d\n", solve(0, 0, 0, 0));
  }
  return 0;
}
