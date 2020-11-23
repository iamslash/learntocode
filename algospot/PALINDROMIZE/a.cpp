// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NAMING

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

// a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다.
int max_overlap(const std::string& a, const std::string& b) {
  int h = a.size();  // hay
  int n = b.size();  // needle
  std::vector<int> pi = get_partial_match(b);
  // begin = mathed = 0에서 시작
  int begin = 0;
  int matched = 0;
  while (begin < h) {
    // 만약 집더미의 해당 글자가 바늘의 해당 글자와 같다면
    if (matched < n && a[begin + matched] == b[matched]) {
      ++matched;
      if (begin + matched == h)
        return matched;
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    char buf[100000];
    scanf("%s", buf);
    //
    std::string s = buf;
    std::string r = buf;
    reverse(r.begin(), r.end());
    // printf("%s\n", s.c_str());
    // printf("%s\n", r.c_str());
    printf("%lu\n", s.size() + r.size() - max_overlap(s, r));
  }
  //
  return 0;
}
