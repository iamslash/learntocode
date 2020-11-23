# Abstract

convex hull algorithm 들중 하나인 gift wrapping algorithm 에 대해
정리한다.

# References

* [Convex Hull | Set 1 (Jarvis’s Algorithm or Wrapping) @ geeksforgeeks](http://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/)

# Problem

점들의 모임 `P` 가 주어지면 모든 점들을 감싸는 다각형을 구하는 문제이다.

# Idea

![](/_img/jarvis.png)

가장 왼쪽의 점을 p 로 정한다. 이 점에서 이 점을 제외한 모든 다른 점들에
선을 그어 선분을 만들었을때 모든 선분들을 반시계 방향으로 갖는 선분
`(p, q)` 를 찾는다. `q` 는 `convex hull` 이다. `q` 를 `p` 로 교체한 후 언급한 과정을
반복한다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(NH)

N - 모든 점들의 숫자
H - hull을 구성하는 점들의 숫자
```

구현은 간단하지만 H 가 N 과 같다면 `O(N^2)` 이다. `Graham scan algorithm -
O(NlgN)` 이 훨씬 효율적이다.