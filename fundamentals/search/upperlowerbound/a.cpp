// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> V = {1, 2, 3, 4, 5};
  auto lit3 = std::lower_bound(V.begin(), V.end(), 3);
  auto lit6 = std::lower_bound(V.begin(), V.end(), 6);
  auto uit3 = std::upper_bound(V.begin(), V.end(), 3);
  auto uit6 = std::upper_bound(V.begin(), V.end(), 6);

  printf("lit3: %d lit6: %d uit3: %d uit6: %d\n",
         *lit3, *lit6, *uit3, *uit6);
  
  return 0;
}
