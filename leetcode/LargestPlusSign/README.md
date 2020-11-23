# Problem

* [Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/)

# Idea

숫자 `N` 과 지뢰의 좌표리스트 `M[][]` 이 주어진다.  `NxN` 크기의
보드를 만들고 `M[][]` 을 제외한 곳들 중 열십자 모양의 `1` 의 모음을
만들어본다. 가장 큰 열십자 모양을 만들때 그것의 반지름의 크기를 구하는
문제이다.

캐시 `C[N][N]` 을 정의한다. 변수 `l, r, u, d` 를 정의한다.  만약 `l,
r, u, d` 에 `C[y][x]` 를 중심으로 왼쪽, 오른쪽 윗쪽, 아래쪽의 최대 `1`
의 개수가 잘 담겨 있다면 `C[y][x] = min(C[y][x], l, r, u, d)` 를
통해 쉽게 `C` 를 채울 수 있다. 그리고 `max(C[y][x])` 가 답이다.

다음과 같이 4 개의 loop 을 이용하면 `l, r, u, d` 를 구하면서 `C[y][x]`
를 갱신할 수 있다.

```cpp
for (int y = 0; y < N; ++y) {
  for (int x = 0; x < N; ++x) { 
    l = C[y][x] == 0 ? 0 : l + 1;
    C[y][x] = min(C[y][x], l);
  }
}
for (int y = 0; y < N; ++y) {
  for (int x = N-1; x >= 0; --x) { 
    r = C[y][x] == 0 ? 0 : r + 1;
    C[y][x] = min(C[y][x], r);
  }
}
for (int y = 0; y < N; ++y) {
  for (int x = 0; x < N; ++x) { 
    u = C[x][y] == 0 ? 0 : u + 1;
    C[x][y] = min(C[x][y], l);
  }
}
for (int y = 0; y < N; ++y) {
  for (int x = N-1; x >= 0; --x) { 
    d = C[x][y] == 0 ? 0 : d + 1;
    C[x][y] = min(C[x][y], r);
  }
}
```

위의 4 개의 loop 는 다음과 같이 1 개의 loop 로도 충분하다.

```cpp
    for (int y = 0; y < N; ++y) {
      int l = 0, r = 0, u = 0, d = 0;
      for (int j = 0, k = N - 1; j < N; ++j, --k) {
        l = C[y][j] == 0 ? 0 : l + 1;
        C[y][j] = std::min(C[y][j], l);
        r = C[y][k] == 0 ? 0 : r + 1;
        C[y][k] = std::min(C[y][k], r);
        u = C[j][y] == 0 ? 0 : u + 1;
        C[j][y] = std::min(C[j][y], u);
        d = C[k][y] == 0 ? 0 : d + 1;
        C[k][y] = std::min(C[k][y], d);
      }
    }
```


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
