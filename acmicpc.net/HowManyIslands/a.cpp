// Copyright (C) 2016 by iamslash
//
// https://www.acmicpc.net/problem/4963

#include <cstdio>
#include <vector>

int M[50][50];
std::vector<std::vector<int> > adj;
std::vector<int> discovered;
int counter;

void BuildGraph(int w, int h) {
  // init global variables
  discovered.clear();
  discovered.resize(w*h, -1);
  adj.clear();
  adj.resize(w*h);
  counter = 0;

  //
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      // dont' need water
      if (M[y][x] == 0)
        continue;

      int here = y * w + x;
      // printf("%d, %d : %d\n", y, x, here);
      
      // N
      if (y - 1 >= 0 && M[y - 1][x] == 1) {
        adj[here].push_back((y - 1) * w + x);
      }
      
      // NE
      if (y - 1 >= 0 && x + 1 < w && M[y - 1][x + 1] == 1) {
        adj[here].push_back((y - 1) * w + (x + 1));
      }     

      // E
      if (x + 1 < w && M[y][x + 1] == 1) {
        adj[here].push_back(y * w + (x + 1));
      }     

      // SE
      if (y + 1 < h && x + 1 < w && M[y + 1][x + 1] == 1) {
        adj[here].push_back((y + 1) * w + (x + 1));
      }     

      // S
      if (y + 1 < h && M[y + 1][x] == 1) {
        adj[here].push_back((y + 1) * w + x);
      }

      // SW
      if (y + 1 < h && x - 1 >= 0 && M[y + 1][x - 1] == 1) {
        adj[here].push_back((y + 1) * w + (x - 1));
      }

      // W
      if (x - 1 >= 0 && M[y][x - 1] == 1) {
        adj[here].push_back(y * w + (x - 1));
      }

      // NW
      if (y - 1 >= 0 && x - 1 >= 0 && M[y - 1][x - 1] == 1) {
        adj[here].push_back((y - 1) * w + (x - 1));
      }

    }
  }
  
}

void Dfs(int here) {
  // printf("%d ", here);

  discovered[here] = counter++;
  // recursion
  for (int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    
    if (discovered[there] == -1) {
      Dfs(there);
    }
  }
}

int HowManyIslands(int w, int h) {
  int r = 0;

  BuildGraph(w, h);
  
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      int i = y * w + x;
      if (M[y][x] == 1 && discovered[i] == -1) {
        Dfs(i);
        ++r;
      }
    }
  }

  return r;
}

int main() {
  int w, h;
  while (scanf("%d %d", &w, &h) != EOF) {
    if (w == 0 || h == 0)
      continue;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        scanf("%d", &M[i][j]);
      }
    }
    printf("%d\n", HowManyIslands(w, h));
  }

  return 0;
}   
