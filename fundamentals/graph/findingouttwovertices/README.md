# Problem

* [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/)

그래프 `adj[][]` 와 두 정점 `u, v` 이 주어지면 두 정점이 한 그래프에 있는지 검증하는 문제이다.

DFS, BFS, DisjointSet 등을 이용해서 해결할 만 하다.

# DFS 

## Idea

`dfs(u)` 를 수행한다. `visit[v] == true`  인지 확인한다.

## Implementation

* [java8](/leetcode2/FindifPathExistsinGraph/MainApp.java)

## Complexity

```
O(V+E) O(V)
```

# BFS

## Idea

`bfs(u)` 를 수행한다. `v` 를 발견하면 true 를 리턴한다.

## Implementation

* [java8](/leetcode2/FindifPathExistsinGraph/MainApp.java)

## Complexity

```
O(V+E) O(V)
```

# DisjointSet

## Idea

[disjoint set](/fundamentals/disjointset/unionfind/README.md) 제작 한다. `u` 와 `v` 가 같은 group 이면 true 를 리턴한다.

## Implementation

* [java8](/leetcode2/FindifPathExistsinGraph/MainApp.java)

## Complexity

```
O(V+E) O(V)
```
