# Problem

> [Minimum Path Cost in a Hidden Grid](https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/)

`GridMaster` 가 다음과 같이 주어진다. 

```
class GridMaster {
    boolean canMove(char direction);
    int move(char direction);
    boolean isTarget();
}
```

출발 지점에서 부터 목표 지점까지의 최소 거리를 구하라.

# Idea

다음과 같은 변수들을 선언한다.

> * `int[] DIR`: `GridMaster::canMove, GridMaster::move` 에 전달할 방향의 매개변수이다.
> * `int[] STEP`: 상,좌,하,우 를 의미하는 delta pos 값이다.
> * `int[][] G`: pos 2 cost graph data
> * `dst`: 목표지점
> * `PriorityQueue<in[]> pq`: Priority Queue for dijkstra

[dfs](/fundamentals/graph/dfs/README.md) 를 이용하여 `G` 를
채운다. 이때 `dfs loop` 에서 다음번 탐색을 위해 제자리로 돌아와야
한다. 이것은 [backtracking](/doc/backtracking.md) 이다.

[dijkstra](/fundamentals/graph/dijkstra/README.md) 를 이용하여 최소
거리를 구한다.

이때 출발지에서 모든 정점에 도달하는 거리를 모두 저장할 필요는
없다. 출발 지점에서 목표 지점까지의 거리만 중요하다. 따라서
[dijkstra](/fundamentals/graph/dijkstra/README.md) 의 `dist[]` 를
유지할 필요는 없다. 또한 한번 방문한 `G[y][x]` 는 다시 방문할 필요가
없다. `G[y][x] = null` 을 수행하자.

`Map<Pair<Integer, Integer>, Integer> G` 대신 `int[][] G` 를 이용하면
time complexity 가 훨씬 효율적이다. 문제의 조건에 의해 `1 <= n, m <=
100` 이다. 따라서 `in[][] G = new int[]{202, 202}` 이면 충분하다. 또한
robot 이 출발하는 곳에서 상하좌우 각각 100 만큼씩 더 이동할 수
있다. dfs 는 `(101, 101)` 부터 해도 좋다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(ElgV) O(V)
```

# Similar Questions

* [Robot Room Cleaner](/leetcode/RobotRoomCleaner/README.md)
