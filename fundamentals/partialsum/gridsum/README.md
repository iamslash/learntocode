# Problem

이차원 배열 `A[][]` 에서 `[y1, x1, y2, x2] (y1 < y2, x1 < x2)` 에 속하는 영역의 합을 구하라.

# Idea

다음과 같이 `gsum[][]` 을 제작한다.

```
A:
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1

gsum:
1 2  3  4  5
2 4  6  8  12
3 6  9  12 16
4 8  12 16 20
5 12 15 20 25

if (y > 0)
  gsum[y][x] += gsum[y-1][x];
if (x > 0)
  gsum[y][x] += gsum[y][x-1];
if (y > 0 && x > 0)
  gsum[y][x] -= gsum[y-1][x-1];
``` 

다음과 같이 `(y1, x1, y2, x2)` 영역의 합을 구한다.

```
 y1 x1 y2 x2
[ 1, 1, 3, 3]

0 0 0 0 0
0 a 0 0 0
0 0 0 0 0
0 0 0 b 0
0 0 0 0 0

area sum = gsum[y2][x2] - 
           gsum[y1 - 1][x2] -
           gsum[y2][x1 - 1] +
           gsum[y1 - 1][x1 - 1]
```

# Implementation

* [c++11](a.cpp)
