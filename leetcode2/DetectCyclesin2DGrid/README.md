# Problem

[Detect Cycles in 2D Grid](https://leetcode.com/problems/detect-cycles-in-2d-grid/)

이차원 배열 `G[][]` 가 주어진다. cycle 이 존재하는지
검증하라.

# Idea

DFS 로 해결할 만하다. `containsCycle` 은 dfsAll 에 해당한다.

`vector<vector<bool>> visit` 를 선언하여 `y,x` 에 대해
방문 여부를 저장한다.

다음과 같은 부분문제 `dfs` 를 정의하여 재귀적으로 구현한다.

```c
bool dfs(vector<vector<char>>& G, vector<vector<bool>>& visit,
  int y, int x, int py, int px)
  
return: cycle or not
     G: graph
 visit: G[y][x] is visited before?
     y: y position
     x: x position
    py: previous y position
    px: previous x position
```

`int ny, nx` 선언하여 새로 이동할 좌표를 저장한다. `ny == py, nx == px` 이면
이동할 수 없다. 또한 `visit[ny][nx] == true` 이면 cycle 을 발견한 것이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(HW)
```
