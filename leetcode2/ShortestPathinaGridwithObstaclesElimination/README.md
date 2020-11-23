# Problem

[Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/)

`0`, `1` 로 구성된 2D 배열 `G[][]` 와 숫자 `k` 가 주어진다. `0` 은
지나갈 수 있고 `1` 은 장애물이다. `(0, 0)` 에서 시작하여 `(h-1, w-1)`
까지 탐색해 보자. `k` 만큼 장애물을 통과할 수 있다. 최소거리를 구하라.

# Idea

이동 거리의 단위가 1 인 최소 거리는
[BFS](/fundamentals/graph/bfsshortestpath/README.md) 를 이용하여
해결할 수 있다. 그 밖의 길찾기는 [path
finding](https://github.com/iamslash/learntocode/blob/master/fundamentals/combinatorialsearch/pathfinding/README.md)
을 참고한다.

`int step` 을 선언하여 전체 비용을 저장한다. `bool visit[y][x][z]` 을
선언하여 `(y, x)` 위치에 `z` 장애물을 제거할 수 있을 때 방문했는지를
저장한다.

`queue<vector<int>> q` 를 선언하여 `{y, x, z}` 를 저장한다.

`(ny, nx)` 는 `int dirs[5] = {-1, 0, 1, 0, -1}` 를 이용한다.

```c
for (int i = 0; i < 4; ++i) {
  ny = y + dirs[i];
  nx = x + dirs[2];
}
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
