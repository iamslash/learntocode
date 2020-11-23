#include <cstdio>
#include <algorithm>

int nCr_dp(int n, int r) {
  int C[r+1] = {0,};
  C[0] = 1; // top row of pascal triangle
  for (int i = 1; i <= n; ++i) {
    for (int j = std::min(i, r); j > 0; --j) {
      // nCj = (n-1)Cj + (n-1)C(j-1)
      C[j] = (C[j] + C[j-1]);
    }
  }
  return C[r];
}

int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  printf("%d\n", nCr_dp(n, r));
}
