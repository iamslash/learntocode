# Problem

[Minimum Area Rectangle II](https://leetcode.com/problems/minimum-area-rectangle-ii/)

# Idea

점들의 모임 `P[][]` 가 주어지면 가장 넓이가 작은 사각형을 구성하는 점
4 개를 선택하여 그 넓이를 구하는 문제이다. 이때 사각형은 마름모꼴 처럼
회전한 것도 포함한다.

다음과 같이 사각형을 형성하는 점 4 개를 찾아서 넓이중 가장 최소인 것을
리턴한다. 이때 선분 `ab` 와 선분 `ac` 는 내적이 `0` 이다. 점 `d`
는 점 `a, b, c` 를 이용하여 구할 수 있다. 점 `d` 가 `P[][]`
에 있다면 사각형의 넓이를 갱신한다.

```
  a      b 
   ------
   |    |
   |    |
   ------
  c      d
```

두 벡터의 내적은 다음과 같다.

```
dot((x0, y0), (x1, y1)) = x0 * x1 + y0 * y1
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3lgN) O(N)
```
