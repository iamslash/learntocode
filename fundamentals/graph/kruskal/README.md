# Abstract

kruskal algorithm 은 MST (minimum spanning tree) 를 구하는
알고리즘이다.

spanning tree 는 graph 에서 모든 정점들을 연결할 수 있는 일부 간선들의
모임이다. spanning tree 는 간선들을 선택하는 방법에 따라 여러 개일 수
있고 tree 이기 때문에 cycle 이 없다.

weighted graph 의 경우 만들어 질 수 있는 spanning tree 들 중에 간선
비용의 합이 최소인 것을 MST (minimum spanning tree) 라고 한다.

# References

* [kruskal algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=71UQH7Pr9kU)
* [Greedy Algorithms | Set 2 (Kruskal’s Minimum Spanning Tree Algorithm)](https://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/)

# Keywords

```cpp
vector<vector<pair<int, int>>> adj
vector<pair<int, pair<int, int>>> edges
DisjointSet ds
vector<pair<int, int>> mst
```

# Problem

그래프 `vector<vector<pair<int, int>>> adj` 가 주어지면 MST 를 구하는 문제이다.

# Idea

먼저 [DisjointSet](/disjointset/unionfind/README.md) `DisjointSet ds`
를 선언한다.  그래프를 `(c,(u,v))` 형태로 `edges` 에 저장하고 `edges`
를 오름차순으로 정렬한다. `c` 는 `cost` 이다. `edges` 의 작은 비용부터 `ds` 에 merge
한다. greedy approach 로 해결할 만 하다.

`edges` 를 순회하면서 다음을 반복한다.

0. `(c,(u,v))` 를 추출한다.
1. `ds.find(u) == ds.find(v)` 이면 건너뛴다.
2. `ds.find(u) != ds.find(v)` 이면 `ds.merge(u, v)` 를 수행한다. `v`
   를 `mst` 에 추가한다. MST 의 길이를 추가하기 위해 `r += c` 를
   수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(|E|lg|E|) O(V)
```

간선을 정렬하는 시간이 시간복잡도를 지배한다.
