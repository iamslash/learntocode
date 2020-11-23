# Problem

[Number of Paths with Max Score](https://leetcode.com/problems/number-of-paths-with-max-score/)

이차원 배열 `G[][]` 가 주어진다. `G[0][0]` 에서 출발하여 `G[n-1][n-1]`
까지 다음과 같은 방법으로 이동한다.

* `G[i][j] == 'X'` 이면 장애물이기 때문에 갈 수 없다.
* `G[y+1][x]`, `G[y][x+1]`, `G[y+1][x+1]` 로 이동할 수 있다.

숫자들의 합이 최대일 경우 그 최대값과 그 경로의 개수를 구하라.

# Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
G:
   0 2 3
   2 1 2
   1 2 0
```

`G[1][1]` 에 도착할 수 있는 방법은 다음과 같이 3 가지이다.

* `G[2][1]`, maxScore: 2, maxPathCnt: 1
* `G[1][2]`, maxScore: 2, maxPathCnt: 1
* `G[2][2]`, maxScore: 0, maxPathCnt: 1

따라서 `G[1][1]` 의 `maxScore` 는 `2` 이고 `maxPathCnt` 는 1 이다.

`int C[n][n][2]` 를 선언하여 `G[y][x]` 의 `maxScore` 와 `maxPathCnt` 를
`C[y][x][0], C[y][x][1]` 에 저장한다.

모든 반복을 마치면 `{C[y][x][0], C[y][x][1]}` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
