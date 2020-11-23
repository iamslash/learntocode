// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NAMING

#include <string>
#include <vector>

void print_v(const std::vector<int> v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n");
}

// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를
// 계산한다.  pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의
// 최대 길이
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


void solve(const std::string& s) {
  std::vector<int> r;
  std::vector<int> pi = get_partial_match(s);
  int k = s.size();
  // print_v(pi);
  while (k > 0) {
    r.push_back(k);
    k = pi[k - 1];
  }
  for (auto it = r.rbegin(); it != r.rend(); ++it) {
    printf("%d ", *it);
  }
}

int main() {
  char sz_father[400000];
  char sz_mother[400000];

  scanf("%s", sz_father);
  scanf("%s", sz_mother);
  //
  std::string newname = sz_father;
  newname += sz_mother;
  //
  solve(newname);
  printf("\n");
  //
  return 0;
}
