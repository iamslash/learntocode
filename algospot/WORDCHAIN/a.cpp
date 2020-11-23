// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/WORDCHAIN

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>


const int ALPHABETS = 26;
int N;

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    std::vector<std::string> words;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
      char buf[128];
      scanf("%s", buf);
      words.push_back(buf);
    }

    printf("%s\n", solve(words).c_str());
  }
  //
  return 0;
}
