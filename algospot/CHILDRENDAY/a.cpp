// Copyright (C) 2017 by iamslash


#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

int N, M, D;

int append(int here, int edge, int mod) {
  int there = here * 10 + edge;
  if (there >= mod) {
    return mod + there % mod;
  }
  return there % mod;
}

std::string solve(std::string digits) {
  std::sort(digits.begin(), digits.end());
  std::vector<int> parent(2 * N, -1);
  std::vector<int> choice(2 * N, -1);
  std::queue<int> q;

  parent[0] = 0;
  q.push(0);

  while (!q.empty()) {
    int here = q.front();
    q.pop();
    for (int i = 0; i < digits.size(); ++i) {
      int there = append(here, digits[i] - '0', N);
      if (parent[there] == -1) {
        parent[there] = here;
        choice[there] = digits[i] - '0';
        q.push(there);
      }
    }
  }
  if (parent[N + M] == -1)
    return "IMPOSSIBLE";

  std::string r;
  int here = N + M;
  while (parent[here] != here) {
    r += static_cast<char>('0' + choice[here]);
    here = parent[here];
  }
  std::reverse(r.begin(), r.end());

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d %d", &D, &N, &M);
    char buf[16] = {0, };
    snprintf(buf, sizeof(buf), "%d", D);
    std::string r = solve(buf);
    printf("%s\n", r.c_str());
  }
}
