# Problem

그래프 `adj[][]` 가 주어지면 사이클이 있는지 검증하는 문제이다.

# Idea

[dfs spanning tree](/fundamentals/graph/dfsspanningtree/README.md) 를 제작한다. back-edge 가 발견되면 사이클이 있다는 얘기이다.

[topological sort](/fundamentals/graph/topologicalsort/README.md) 를 수행한다.
back-edge 가 발견되면 사이클이 있다는 얘기이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(E+V) O(1)
```