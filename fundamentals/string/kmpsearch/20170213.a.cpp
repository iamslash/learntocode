// Copyright (C) 2016 by iamslash

#include <string>
#include <vector>
#include <algorithm>

void print_v(const std::vector<int> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n");
}

std::vector<int> get_partial_match(const std::string& N) {
  int m = N.size();
  std::vector<int> pi(m, 0);
  // KMP로 자기자신을 찾는다.
  // N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안된다.
  int begin = 1, matched = 0;
  // 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
  while (begin + matched < m) {
    if (N[begin + matched] == N[matched]) {
      ++matched;
      pi[begin + matched - 1] = matched;
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched-1];
        matched = pi[matched - 1];
      }
    }
  }
  return pi;
}

std::vector<int> kmp_search(const std::string& H, const std::string& N) {
  int h = H.size();
  int n = N.size();
  std::vector<int> r;
  //
  std::vector<int> pi = get_partial_match(N);
  //
  int begin = 0;
  int matched = 0;
  while (begin < h - n) {
    // 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
    if (matched < n && H[begin + matched] == N[matched]) {
      ++matched;
      if (matched == n)
        r.push_back(begin);
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return r;
}

int main() {
  std::string h = "hellomynameisslashmynameisnotfoo";
  std::string n = "myname";

  std::vector<int> r = kmp_search(h, n);

  printf("%s\n", h.c_str());
  printf("%s\n", n.c_str());
  print_v(r);
  
  //
  return 0;
}
