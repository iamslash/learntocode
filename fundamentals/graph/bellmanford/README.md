# Abstract

[Dijkstra algorithm](/fundamentals/graph/dijkstra/README.md) 과 같은
  단일 시작점 최단 경로 알고리즘이다. [Dijkstra
  algorithm](/fundamentals/graph/dijkstra/README.md) 과 달리
  음수간선의 경우도 최단 경로를 구할 수 있다.

# reference

- [bellman-ford in 5 minutes at youtube](https://www.youtube.com/watch?v=obWXjtg0L64)  

# Problem

정점과 간선의 가중치가 이차원 배열 `adj` 로 주어진다. 정점 `0` 에서
모든 정점들로 가는 최단거리들을 구하는 문제이다.

# Keyword

```cpp
dist[], G[][], bool updated
```
# Idea

간선을 순회 하면서 최단 경로를 발견하는 과정을 relax 라고 한다. relax
가 없다면 loop 을 종료한다. 마지막 순회에도 relax 가 있다면 음수
사이클이 있다. 음수 사이클이 있다면 빈 배열을 반환한다. 

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V^2E) O(V)
```
