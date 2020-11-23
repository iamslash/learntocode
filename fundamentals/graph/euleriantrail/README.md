# Problem

그래프 `adj[][]` 와 정점 `u, v` 가 주어지면 `u` 에서 출발하여 `v` 까지 모든 간선을 정확히 한번씩만 지나는 경로를 구하는 문제이다.

# Keyword

```
adj, order, dfs, eulerian_trail
```

# Idea

일명 한 붓 그리기에 해당한다. [eulerian circuit](fundamentals/graph/euleriancircuit/README.md) 처럼 모든 간선을 지나지만 시작점과 끝점이 다른 경로이다. 홀수점은 2 개이어야 한다. 0 개 이면 [eulerian circuit](fundamentals/graph/euleriancircuit/README.md) 이 존재한다.

`euler_trail(u, v)` 은 `(u, v)` 간선을 하나 만들고 [eulerian circuit](fundamentals/graph/euleriancircuit/README.md) 을 구한다. 그 다음에 `(u, v)` 의 간선을 지우면 된다. `u, v` 는 홀수점 이고 나머지는 짝수점이어야 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(1)
```