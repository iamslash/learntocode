// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>

// l
//         m
//                    r
// 1 5 4 3 2 10 7 6 8 9
//
int binary_search(std::vector<int>& v, int k) {
  std::vector<int> vv = v;
  std::sort(vv.begin(), vv.end());
  int l = 0, r = v.size()-1, m, rr = -1;
  while (l <= r) {
    m = (l + r) / 2;
    if (k == vv[m]) {
      rr = m;
      break;
    } else if (k < vv[m]) {
      r = m - 1;
    } else if (k > vv[m]) {
      l = m + 1;
    }
  }
  printf("%d\n", rr);
  if (rr >= 0) {
    rr = std::find(v.begin(), v.end(), k) - v.begin();
  }
  return rr;
}

int main()
{
  std::vector<int> v = {1, 5, 4, 3, 2, 10, 7, 6, 8, 9};
  printf("%d\n", binary_search(v, 5));
  return 0;
}
