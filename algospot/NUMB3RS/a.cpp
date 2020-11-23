#include <cstdio>
#include <vector>

int N, D, P;  // town count, days, start
int adj[50][50];
int end[50];
int deg[50];
double CACHE[51][101]; //

// days이후에 star에서 시작해서 end에 있는지 여부 
double solve(int start, int end, int days) {
  printf("%d %d %d\n", start, end, days);

  // base condition
  if (days == D)
    return (start == end) ? 1.0 : 0.0;

  // memoization
  double & r = CACHE[start][days];
  if (r > -1.0)
    return r;

  // recursion
  r = 0.0;
  for (int there = 0; there < N; ++there) {
    if (adj[start][there] > 0) {
      r += solve(there, end, days + 1) / deg[there];
    }
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    // init var
    memset(adj, 0, sizeof(adj));
    memset(deg, 0, sizeof(deg));
    memset(end, 0, sizeof(end));
    memset(CACHE, -1, sizeof(CACHE));

    //
    scanf("%d %d %d", &N, &D, &P);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%d", &adj[i][j]);
        if (adj[i][j] > 0) {
          deg[i]++;
        }
      }
    }
    int endcnt;
    scanf("%d", &endcnt);
    for (int i = 0; i < endcnt; ++i)
      scanf("%d", &end[i]);
    for (int i = 0; i < endcnt; ++i) {
      printf("%0.8f ", solve(end[i], P, 0));
    }
    printf("\n");
  }
}

