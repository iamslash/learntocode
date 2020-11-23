# Abstract

prim algorithm 은 MST(minimum spanning tree) 를 구하는 알고리즘이다.

spanning tree 는 graph 에서 모든 정점들을 연결할 수 있는 일부 간선들의 모임이다. spanning tree 는 간선들을 선택하는 방법에 따라 여러 개일 수 있고 트리이기 때문에 사이클이 없다.

weighted graph 의 경우 만들어 질 수 있는 spanning tree 들 중에 간선 비용의 합이 최소인 것을 MST (minimum spanning tree) 라고 한다.

# References

* [prim algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=cplfcGZmX7I)
* [Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))](http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/)

# Keywords

```cpp
adj[][]
vector<pair<int, int>> mst, 
vector<bool> added
vector<int> mincost
vector<int> parent
```

# Problem

그래프 `adj[][]` 가 주어지면 MST 를 구하는 문제이다.

# Idea

정점의 개수 만큼 다음을 반복한다.

0. 방문하지 않은 노드들 중 가장 최소의 비용을 소유한 노드를 `u` 라고 하자.
1. `u != parent[u]` 이면 `mst.push_back(parent[u], u)` 를 수행 한다.
2. `u` 의 이웃들을 `v` 라고 하고 `duv = adj[u][v]` 라고 하자. `mst` 에 아직 추가되지 않았고 `duv < mincost[v]` 인 `v` 를 찾아 `parent[v] = u; mincost[v] = duv` 를 수행한다.

다음은 `A, B, C, D` 노드가 주어질 때 `A` 노드 부터 시작하여 MST가
만들어지는 과정을 표현한 그림이다.

![](/_img/prim.png)

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(|V|^2+|E|) O(1)
```

dense graph 인 경우 모든 정점이 연결되어 있을 테니 간선의 개수는 정점의 개수와 같다. 즉, `|E| = |V|^2` 이다. 따라서 [kruskal algorithm](/fundamentals/graph/kruskal/README.md) 의 시간 복잡도는 `O(ElgE)` 였기 때문에 `O(V^2)` 가 될 수 있다. 그러므로 dense graph 의 경우는 prim algorithm 이 더욱 효율적이다.
