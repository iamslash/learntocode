// Copyright (C) 2016 by iamslash

// g++ a.cpp -std=c++11 -o a.exe

#include <cstdio>
#include <cstdint>

#define MAX_N 65535

int N;
// explodes[i] = bitmask set which is i-th element will be exploded with
int explodes[MAX_N] = {0, };

// set is stable ???
bool is_stable(int set) {
  for (int i = 0; i < N; ++i) {
    if ((set & (1 << i)) && (set & explodes[i]))
      return false;
  }
  return true;
}

// get count of maximal stable set
int solve() {
  int r = 0;

  for (int set = 1; set < (1 << N); ++set) {
    if (!is_stable(set))
      continue;

    bool can_extend = false;
    for (int i = 0; i < N; ++i) {
      if (((set & (1 << i)) == 0) && ((set & explodes[i]) == 0)) {
        // printf("%x %d\n", set, i);
        can_extend = true;
        break;
      }
    }
    if (!can_extend)
      ++r;
  }

  return r;
}

int main() {
  // total 5 elements
  N = 4;
  // 0th element will explode with 3th element
  explodes[0] = 0x02;  // 00000010
  explodes[1] = 0x01;  // 00000001
  explodes[2] = 0x08;  // 00001000
  explodes[3] = 0x04;  // 00000100
  // printf("%x is %d\n", set, is_stable(0x03));
  // printf("%x is %d\n", set, is_stable(0x01));
  printf("%d\n", solve());

  return 0;
}
