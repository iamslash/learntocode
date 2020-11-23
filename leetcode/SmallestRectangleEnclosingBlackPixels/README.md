# Problem

* [Smallest Rectangle Enclosing Black Pixels](https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/)

# Idea

다음과 같은 보드가 주어진다. `1` 을 감싸는 최소 직사각형의
넓이를 구하는 문제이다.

```
  0010
  0110
  0100
```

보드를 처음부터 끝까지 순회한다. 다음과 같은 4 가지
변수를 채운다.

```cpp
int sy : 처음 등장하는 `1` 의 y 좌표
int ey : 마지막 등장하는 `1` 의 y 좌표
int sx : 처음 등장하는 `1` 의 x 좌표
int ex : 마지막 등장하는 `1` 의 x 좌표
```

`(ey-sy+1) * (ex-sx+1)` 이 답이다.

`ey, sy, ex, sx` 를 binary serach 로 찾을 수도 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(1)
```