# Problem

이차원 배열 `A[][]` 에서 `[y1, x1, y2, x2] (y1 < y2, x1 < x2)` 에 속하는 영역의
합을 구하라.

# Idea

이차원 부분합 `psum[][]` 을 미리 계산하자. `grid sum` 은 `psum[][]` 을 이용하여
다음과 같이 구한다.

```
 y1 x1 y2 x2
[ 1, 1, 3, 3]

0 0 0 0 0
0 a 0 0 0
0 0 0 0 0
0 0 0 b 0
0 0 0 0 0

grid sum = psum[y2][x2] - 
           psum[y1 - 1][x2] -
           psum[y2][x1 - 1] +
           psum[y1 - 1][x1 - 1]
```

# Implementation

* [c++11](a.cpp)
