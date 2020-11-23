#include <cstdio>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int n = 0;
  int x = a, y = b;
  while (true) {
    ++n;
    x = x * 3;
    y = y * 2;
    if (x > y)
      break;
  }
  // printf("%d %d %d %d\n", a, b, x, y);
  printf("%d\n", n);
  return 0;
}   
