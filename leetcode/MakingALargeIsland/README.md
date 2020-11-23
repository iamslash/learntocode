# Problem

* [Making A Large Island](https://leetcode.com/problems/making-a-large-island/)

# Idea

`0, 1` 로 구성된 `HxW` 크기의 그리드가 주어졌을 때
하나의 `0` 을 `1` 로 수정했을 때 최대 섬의 크기를 구하는 문제이다.

그리드의 `1` 로 이루어진 섬들의 크기를 각각 구하고
각 섬들을 특별한 색으로 칠해놓자.

이후 `0` 인 셀을 찾아서 `상하좌우` 에 색이 칠해진 섬이
인접해 있다면 그 크기를 더하면 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
