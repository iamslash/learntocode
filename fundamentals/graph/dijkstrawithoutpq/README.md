# Abstract

우선순위 큐를 사용하지 않는 방법이 더 빠른 경우가 있다.  우선순위 큐를
이용하는 [dijkstra](/fundamentals/graph/dijkstra/README.md) 와 `u` 를 찾는 방법이
다르다. 특정정점에서 나머지정점들의 거리를 저장하는 `dist[]` 에서 가장 거리가 작고 아직 방문하지 않는 녀석을 `u` 로 한다.

# Problem

정점과 간선의 가중치가 이차원 배열 `adj` 로 주어진다. 정점 `0` 에서 모든 정점들로 가는 최단거리들을 구하는 문제이다.

# Keyword

```
adj[][], dijkstra, dist, visited
```

# Idea



# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(|V|^2 + |E|)
```
