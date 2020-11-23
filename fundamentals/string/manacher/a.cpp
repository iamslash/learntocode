// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

  // j: center index of last max palindrom substring
  // r: right most index of last max plaindrom substring
  // j - i' = i - j
  // i' = 2 * j - i
  //
  //     0 1 2 3 4 5
  // s : b a n a n a
  // z : 0 0 1 2 1 0
  //             i
  //           j
  //               r

std::string solve(std::string h) {
  // length of odd string
  int n = 2 * h.size() + 1;
  std::string s(n, '.');
  std::vector<int> z(n);
  for (int i = 0; i < h.size(); ++i)
    s[2 * i + 1] = h[i];
  for (int j, r = 0, i = 0; i < n; ++i) {
    if (i < r && z[2 * j - i] != r - i) {
      z[i] = std::min(z[2 * j - i], r - i);
    } else {
      j = i;
      r = std::max(r, i);
      while (r < s.size() && (2 * j - r) >= 0 &&
             s[r] == s[2 * j - r])
        r++;
      z[i] = r - j;
    }
  }
  for (int a : z)
    printf("%d ", a);
  printf("\n");
  int x = std::max_element(z.begin(), z.end()) - z.begin();
  return h.substr((x - z[x] + 1) / 2, z[x] - 1);
}

int main() {
  printf("%s\n", solve("banana").c_str());
  return 0;
}
