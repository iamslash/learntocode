// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GALLERY

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>

const int MAX_V = 1000;

int G, H;
std::vector<int> adj[MAX_V];
std::vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
// 지금 까지 설치한 카메라의 총수
int installed;

// here로 부터 깊이 우선 탬색을 하고, here의 정보를 반환한다.
int Dfs(int here) {
  visited[here] = true;
  int children[3] = {0, 0, 0};

  for (int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    if (!visited[there])
      ++children[Dfs(there)];
  }

  // 자손 노드중 감시되지 않는 노드가 있을 경우 카메라를 설치한다.
  if (children[UNWATCHED]) {
    ++installed;
    return INSTALLED;
  }

  // 자손노드 중 카레가ㅏ 설치된 노드가 있을 경우 설치할 필요가 없다.
  if (children[INSTALLED]) {
    return WATCHED;
  }

  return UNWATCHED;
}

// 그래프를 감시하는데 필요한 카메라의 최소 수를 반환한다.
int InstallCamera() {
  installed = 0;
  visited = std::vector<bool>(G, false);
  for (int u = 0; u < G; ++u) {
    if (!visited[u] && Dfs(u) == UNWATCHED) {
      ++installed;
    }
  }
  return installed;
}


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

    printf("%d\n", InstallCamera());
  }
  //
  return 0;
}
