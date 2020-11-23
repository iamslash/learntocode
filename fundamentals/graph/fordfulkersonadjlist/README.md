# Abstract

- ford fulkerson algorithm 을 [adjacency matrix](fundamentals/graph/fordfulkersonadjmatrix/README.md) 대신 adjency list 를 이용하여 구현한 알고리즘이다.

# References

- [for fulkerson in 5 minutes at youtube](https://www.youtube.com/watch?v=Tl90tNtKvxs)

# Problem

그래프 `adj[][]` 와 정점 `src, snk` 가 주어지면 최대유량을 구하는 문제이다.

# Keyword
```cpp
capacity[][], Edge, add_edge, get_edge 
ford_fulkerson, parent, q
```

# Idea

- find a augmenting path
  - non-full forward edges (유량이 용량보다 작은 정방향 간선들)과
    non-empty backward edges (유량이 비어있지 않은 역방향 간선들) 을 대상으로
    path 를 찾는다.
- compute the bottle neck capacity
  - path 에서 각 간선의 capacity 를 초과하지 않는 최대 유량을 계산한다.
- augment each edge and the total flow
  - path 의 각 간선의 유량을 더한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(min(|E|f, |V||E|^2)
```