# Abstract

kruskal algorithm 은 MST (minimum spanning tree) 를 구하는 알고리즘이다.

spanning tree 는 graph 에서 모든 정점들을 연결할 수 있는 일부 간선들의 모임이다. spanning tree 는 간선들을 선택하는 방법에 따라 여러 개일 수 있고 tree 이기 때문에 cycle 이 없다.

weighted graph 의 경우 만들어 질 수 있는 spanning tree 들 중에 간선 비용의 합이 최소인 것을 MST (minimum spanning tree) 라고 한다.

[kruskal](/fundamentals/graph/kruskal/README.md) 은 edge 를 중심으로 탐색한다. [prim](/fundamentals/graph/prim/README.md) 은 vertex 를 중심으로 탐색한다.

# References

* [kruskal algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=71UQH7Pr9kU)
* [Greedy Algorithms | Set 2 (Kruskal’s Minimum Spanning Tree Algorithm)](https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/)

# Keywords

```java
Queue<int[]> pq
DisjointSet ds
```

# Problem

그래프 `int[][] pts` 가 주어지면 MST 를 구하는 문제이다.

# Idea

1. 그래프에서 각 간선의 비용을 계산합니다. 이 때, 두 정점 간의 거리(간선 비용)는 맨해튼 거리로 계산합니다. 모든 정점 쌍에 대해 거리(간선 비용)를 계산하여 우선순위 큐(Priority Queue)에 저장합니다.

2. 우선순위 큐에 저장된 간선들을 비용 순으로 정렬합니다. 우선순위 큐의 특성상, 자동으로 비용이 가장 작은 간선부터 차례로 처리할 수 있습니다.

3. [Disjoint Set](/fundamentals/disjointset/unionfind/README.md) 자료구조를 사용하여 각 정점을 독립된 집합으로 초기화합니다. 이 자료구조는 Union-Find 알고리즘을 사용하여 각 정점의 루트를 찾고 두 정점을 하나의 집합으로 병합하는 기능을 합니다.

4. 우선순위 큐에서 비용이 가장 작은 간선부터 하나씩 꺼내어 두 정점이 같은 집합에 속해 있는지 확인합니다. 만약 다른 집합에 속해 있다면, 해당 간선을 MST의 일부로 선택하고 두 정점을 병합합니다. 이 과정을 모든 정점이 하나의 집합으로 병합될 때까지 반복합니다.

5. 선택된 간선들의 비용 합을 반환합니다.

이 과정을 통해 그래프의 모든 정점을 최소 비용으로 연결하는 MST를 구할 수 있습니다.

# Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

# Complexity

```
O(|E|lg|E|) O(V)
```

간선을 정렬하는 시간이 시간복잡도를 지배한다.
