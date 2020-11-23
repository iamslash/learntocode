// Copyright (C) 2017 by iamslash
#include <string>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

std::vector<int> makepi(const std::string& N) {
  int n = N.size();
  std::vector<int> pi(n, 0);
  // KMP로 자기자신을 찾는다.
  // N을 N에서 찾는다. i = 0이면 자기 자신을 찾아버리니까 안된다.
  int i = 1, j = 0;
  // 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
  while (i + j < n) {
    if (N[i + j] == N[j]) {
      ++j;
      pi[i + j - 1] = j;
    } else {
      if (j == 0) {
        ++i;
      } else {
        i += j - pi[j-1];
        j = pi[j-1];
      }
    }
  }
  return pi;
}

std::vector<int> kmp_search(const std::string& H,
                            const std::string& N) {
  int h = H.size(), n = N.size();
  
  std::vector<int> r;
  std::vector<int> pi = makepi(N);
  // printv(pi);
  int i = 0, j = 0;
  while (i <= h - n) {
    if (j < n && H[i+j] == N[j]) {
      // matched     
      ++j;
      if (j == n)
        r.push_back(i);
    } else {
      // dot not matched
      if (j == 0) {
        ++i;
      } else {
        i += j - pi[j-1];
        j = pi[j-1];
      }
    }
  }
  return r;
}


int main() {
  std::string H = "kaabaabakaabaabac";
  std::string N = "aabaabac";
  auto r = kmp_search(H, N);
  printv(r);
  
  return 0;
}
