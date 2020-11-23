# Problem

[Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

이차원 배열 `G[][]` 가 주어진다. `G[][]` 는 `0, 1` 로 구성되어
있다. `0` 은 지나갈 수 있고 `1` 은 장애물을 의미한다. `G[0][0]` 에서
출발하여 `G[h-1][w-1]` 까지 갈 수 있는 경로의 수를 구하라.

# Idea

한편 `G[0][0] == 1 || G[h-1][w-1] == 1` 인 경우는 경로를 구성할 수
없다.

`vector<vector<int>> C(h, vector<int>(w))` 를 선언하여 `C[y][x]` 에
`G[0][0]` 에서 출발하여 `G[y][x]` 까지 도착할 수 있는 경로의 수를
저장한다. 다음과 같은 daynamic programming equation 을 발견할 수 있다.

```
C[y][x] = C[y-1][x] + C[y][x-1]
```

`vector<int> C(w)` 을 이용하면 space complexity 를 개선할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(1)
```
