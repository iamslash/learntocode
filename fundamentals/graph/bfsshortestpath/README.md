# Abstract

노드 `a` 에서 노드 `b` 까지 BFS(breadth first search) 를 이용하여 최단 경로를
찾아 보자.

# Idea

출발지에 해당하는 `a` 노드 부터 [BFS](/fundamentals/graph/BFS/README.md) 를 이용하여 모든 노드들을
방문한다. 방문 하는 노드의 부모 노드를 `parent[]` 에 저장하자.

`parent[]` 를 이용하여 b 노드 부터 a 노드 까지의 경로를 역추적한다.  간선의
비용이 일정하기 때문에 `parent[]` 를 이용한 경로는 최단 경로에 해당한다.

# Keyword

```
adj, get_shortest_path, bfs, parent, found, q
```

# Implementation

* [c++11](a.cpp)

# Complexity

V를 노드 E를 간선 이라고 하자.

```
  adjacency list : O(V+E) O(V)
adjacency matrix : O(V^2) O(V)
```