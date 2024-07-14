# Abstract

prim algorithm 은 MST(minimum spanning tree) 를 구하는 알고리즘이다.

spanning tree 는 graph 에서 모든 정점들을 연결할 수 있는 일부 간선들의 모임이다. spanning tree 는 간선들을 선택하는 방법에 따라 여러 개일 수 있고 트리이기 때문에 사이클이 없다.

weighted graph 의 경우 만들어 질 수 있는 spanning tree 들 중에 간선 비용의 합이 최소인 것을 MST (minimum spanning tree) 라고 한다.

[kruskal](/fundamentals/graph/kruskal/README.md) 은 edge 를 중심으로 탐색한다. [prim](/fundamentals/graph/prim/README.md) 은 vertex 를 중심으로 탐색한다.

# References

* [prim algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=cplfcGZmX7I)
* [Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))](http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/)

# Keywords

```java
Set<Integer> mst
int[] dists
```

# Problem

그래프 `adj[][]` 가 주어지면 MST 를 구하는 문제이다.

# Idea

# Idea

1. 그래프에서 시작 정점을 선택하고, 해당 정점을 MST의 일부로 포함시킵니다. 이 구현에서는 첫 번째 정점(인덱스 0)을 시작 정점으로 선택합니다.

2. 선택된 시작 정점에서 다른 모든 정점까지의 거리를 계산하여 배열에 저장합니다. 이 배열은 각 정점까지의 최소 거리를 추적하는 역할을 합니다.

3. MST에 포함된 정점들을 추적하기 위해 집합(Set)을 사용합니다. 처음에는 시작 정점만 포함됩니다.

4. MST에 포함되지 않은 정점들 중에서 현재 MST에 가장 가까운 정점을 선택합니다. 이는 거리 배열에서 최소 값을 가지는 정점을 선택하는 것으로 이루어집니다.

5. 선택된 정점을 MST에 추가하고, 해당 정점과 연결된 다른 정점들까지의 거리를 업데이트합니다. 만약 새로운 정점과 연결된 거리가 기존의 거리보다 작다면, 거리 배열을 업데이트합니다.

6. 위 과정을 모든 정점이 MST에 포함될 때까지 반복합니다.

7. 선택된 간선들의 비용 합을 반환합니다.

이 과정을 통해 그래프의 모든 정점을 최소 비용으로 연결하는 MST를 구할 수 있습니다.

![](/_img/prim.png)

# Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

# Time Complexity

```
O(|V|^2+|E|) O(1)
```

dense graph 인 경우 모든 정점이 연결되어 있을 테니 간선의 개수는 정점의 개수와 같다. 즉, `|E| = |V|^2` 이다. 따라서 [kruskal algorithm](/fundamentals/graph/kruskal/README.md) 의 시간 복잡도는 `O(ElgE)` 였기 때문에 `O(V^2)` 가 될 수 있다. 그러므로 dense graph 의 경우는 prim algorithm 이 더욱 효율적이다.
