# Problem

그래프에 대한 데이터가 주어질 때 그래프들 중 가장 연결이 많이 되어
있는 그래프의 노드 개수를 출력하는 프로그램을 작성하라.

입력은 다음과 같다.  첫번째 줄에 정점의 개수 `V` 와 간선의 개수 `E` 가
온다. 그리고 `E` 줄 만큼 연결 해야할 두 정점 `X, Y` 가 온다.

출력은 가장 큰 그래프의 노드 개수이다.

# Idea

[union-find](/fundamentals/disjointset/unionfind/README.md) 를 이용해서 해결한다.
`DisjointSet class` 에 `rank` 와 비슷하게 `size` 를
두어서 노드가 merge될 때 마다 `size` 를 갱신한다.

[DFS](/fundamentals/graph/dfs/README.md) 를 이용해서 해결할 수도 있다.

# Implementation

* [c++](a.cpp)

# Complexity

```
O(alpha(N)) O(N)
```

alpha is [inverse Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function#Inverse)
