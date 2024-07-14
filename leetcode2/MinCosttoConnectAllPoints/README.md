# Problem

[Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)

position 의 모음 `P[][]` 가 주어진다. `manhatan distance` 를 점과 점
사이의 비용계산에 이용한다. 모든 점들을 최소 비용으로 연결해 보자.  그
비용을 구하라.

# Prim Algorithm

## Keywords

```java
Set<Integer> mst
int[] dists
```

## Idea

모든 점들은 연결된 graph 에서 MST (minimum spanning tree) 를 구하는 문제이다. [kruskal](/fundamentals/graph/kruskal/README.md) 혹은 [prim](/fundamentals/graph/prim/README.md) 을 이용하여 해결한다.

## Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

## Complexity

```
O(V^2) O(V)
```

# Kruskal Algorithm

## Keywords

```
```

## Idea

모든 점들은 연결된 graph 에서 MST (minimum spanning tree) 를 구하는 문제이다. [kruskal](/fundamentals/graph/kruskal/README.md) 혹은 [prim](/fundamentals/graph/prim/README.md) 을 이용하여 해결한다.

## Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

## Complexity

```
O(ElgE) O(E)
```
