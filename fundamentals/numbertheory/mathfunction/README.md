# Abstract

몇 가지 math function 들에 대해 정리한다.

# round

```cpp
int main() {
  int a = (int)round(3.2);
  int b = (int)round(3.5);
  int c = (int)round(-3.2);
  int d = (int)round(-3.5);
  printf("%d, %d, %d, %d\n", a, b, c, d);
  // 3, 4, -3, -4
  return 0;
}
```

