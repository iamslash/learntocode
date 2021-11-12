# Problem

* [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)

그래프 `G` 가 주어지면 bipartite graph 가 될 수 있는지 검증하라.

# References

* [Check whether a given graph is Bipartite or not](https://www.geeksforgeeks.org/bipartite-graph/)

# Idea

그래프의 노드를 두가지 색으로 번갈아 칠해 가면서 탐색하자.  만약
연결된 두 노드가 같은 색으로 칠해야 한다면 bipartite graph 가 될 수
없다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(V+E) O(N)
```
