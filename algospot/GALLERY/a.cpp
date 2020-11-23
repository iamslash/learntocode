// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GALLERY

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>


int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &G);
    scanf("%d", &H);

    for (int i = 0; i < G; ++i) {
      adj[i].clear();
    }

    for (int i = 0; i < H; ++i) {
      int x, y;
      scanf("%d %d", &x, &y);
      adj[x].push_back(y);
    }

    printf("%d\n", install_camera());
  }
  //
  return 0;
}
