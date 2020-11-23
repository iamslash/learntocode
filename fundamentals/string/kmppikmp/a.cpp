// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <algorithm>

std::vector<int> makepi(const std::string& N) {
  int n = N.size();
  std::vector<int> r(n, 0);
  // KMP로 자기자신을 찾는다.
  // N을 N에서 찾는다. i = 0이면 자기 자신을 찾아버리니까 안된다.
  int i = 1, j = 0;
  // 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
  while (i + j < n) {
    if (N[i + j] == N[j]) {
      ++j;
      r[i + j - 1] = j;
    } else {
      if (j == 0) {
        ++i;
      } else {
        i += j - r[j-1];
        j = r[j - 1];
      }
    }
  }
  return r;
}

int main() {
  std::string n = "aabaabac";

  auto r = makepi(n);

  for (int a : r)
    printf("%d ", a);
  printf("\n");

  //
  return 0;
}
