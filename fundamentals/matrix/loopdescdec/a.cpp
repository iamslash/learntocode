#include <cstdio>
#include <vector>

int main() {
  int n = 10;
  std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    printf("%d : ", i);
    for (int j = n-i-1; j >= 0; --j) {
      printf("%d ", j);
    }
    printf("\n");
  }

  return 0;
}