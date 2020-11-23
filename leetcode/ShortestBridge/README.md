# Problem

[Shortest Bridge](https://leetcode.com/problems/shortest-bridge/)

# Idea

그래프 `A[][]` 와 `1` 로 구성된 두개의 섬이 주어진다.  두개의 섬을
잇는 최소 거리의 다리를 구하는 문제이다.

첫번째 섬을 모두 `2` 로 칠한다. 그리고 `2` 와 인접한 `0` 을 `3` 으로
칠한다. 그리고 `3` 과 인접한 `0` 을 `4` 로 칠한다.

이와 같이 `c` 와 인접한 `0` 을 `c+1` 로 칠한다.
만약 `0` 이 아닌 `1` 을 만나면 두번째 섬을 찾은 것이다.
`c-2` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3) O(N)
```
