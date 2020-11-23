# Problem

[Number of Ships in a Rectangle](https://leetcode.com/problems/number-of-ships-in-a-rectangle/)

# Idea

사각형의 두점 `topright, bottomLeft` 과 `Sea` 의 객체 `sea` 가
주어진다. `sea.hashShips(t, b)` 는 `t, b` 영역에 존재하는 배의 개수를
리턴한다. 점 하나에 배는 최대 한개 존재할 수 있다. `topRight,
bottomLeft` 영역에 존재하는 배의 개수를 구하는 문제이다.

다음과 같이 부분문제 `dfs(x0, x1, y0, y1)` 을
정의하고 divide and conquor 로 해결할만 하다.

```
dfs(x0, x1, y0, y1)

x0, y0 : Bottom Left
x1, y1 : Top Right
```

영역을 4 개로 나누고 배의 개수를 구한다음 모두 더하여 리턴한다.
`sea.hashShips` 에 전달하는 좌표는 서로 겹치지 않아야 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(K^M) O(NMK)
```
