# Abstract

- [Dijkstra algorithm](/fundamentals/graph/dijkstra/README.md), [Bellman-Ford algorithm](/fundamentals/graph/bellmanford/README.md) 은 단일 시작점 최단 경로
  알고리즘들이다. floyd algorithm 은 이차원 배열을 이용하여 정점의 모든
  쌍에 대해 경유지를 활용하여 최단 거리를 구하는 알고리즘이다.

# References

- [floyd in 4 minutes at youtube](https://www.youtube.com/watch?v=4OQeCuLYj-4)

# Keywords

```
adj[][], via[][], floyd, reconstruct
```

# Problem

그래프 `adj[][]` 가 주어지면 모든 정점들 사이의 최단 거리를 구하는 문제이다.

# Idea

`adj[u][v]` 는 `u` 노드와 `v` 노드의 거리를 의미한다. `via[u][v]` 는 `u` 노드와 `v` 노드 사이에 경유 노드를 의미한다. 없으면 `-1` 이다. 

`k` 는 경유지, `i` 는 시작점, `j` 는 끝점으로 완전 탐색하며
`adj[i][j] > adj[i][k] + adj[k][j]` 인지 확인하여 `adj[i][j]` 를 갱신한다. 이때 선택된 경유 노드 `k` 는 `via[u][v]` 에 저장한다. 

탐색을 마치면 `adj[u][v]` 는 `u` 노드와 `v` 노드의 최소   거리가 저장되고 `via[u][v]` 는 그때 경유하는 `k` 노드가 저장된다. 없으면 `-1` 이 저장된다.

탐색경로는 전체 경로의 시작점과 끝점 사이에 경유정점을 재귀적으로 삽입하여 구한다.

# Implementations

* [c++11](a.cpp)

# Complexity

```
O(V^3) O(V^2)
```