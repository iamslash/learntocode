# Problem

노드 `V(vertex)` 와 간선 `E(edge)` 이 주어졌을 때 특정 노드를 시작으로 너비 우선으로 탐색하는 방법이다.

간선의 비용이 1 인 그래프에서 최단경로의 비용을 쉽게 구할 수 있다.

# References

* [Breadth First Traversal for a Graph | GeeksforGeeks @ youtube](https://www.youtube.com/watch?v=0u78hx-66Xk)
  
# Idea

예를 들어 다음과 같은 그래프를 가정하자.

```
         0
       / | \
      1  2  3
    / | \
   4  5  6 
```

`0` 을 방문하고 깊이가 같은 노드들 중 너비가 넓은 노드를 검색한다. 그런 노드가
없으므로 깊이가 하나 증가한 노드 `1` 을 방문한다. `1` 과 깊이가 같고 너비가 하나
넓은 노드 `2` 를 방문 한다. `2` 와 깊이가 같고 너비가 하나 넓은 `3` 을 방문한다.
이렇게 너비를 하나씩 증가하여 방문하는 방법을 BFS (Breadth First Search) 라고
한다.

큐를 활용하면 반복적으로 BFS 할 수 있다.

## Implementation

* [c++11](a.cpp)
* [java](MainApp.java)
* [python](a.py)
* [c#](a.cs)

## Time Complexity

```
  adjacency list : O(V+E) O(V)
adjacency matrix : O(V^2) O(V)
```
