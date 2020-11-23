# Problem

[Shortest Path with Alternating Colors](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

# Idea

노드의 개수 `N`, 빨간색 간선의 모음 `R[]`, 파란색 간선의 모음 `B[]` 이
주어진다. 노드를 탐색할 때는 빨간색과 파란색을 교대로 방문해야
한다. 노드 `0` 부터 모든 노드까지의 최소 경로를 구하는 문제이다. 만약
경로가 없다면 `-1` 을 표기한다.

간선의 비용은 1 이다. BFS 로도 충분히 구할 수 있다. 단, 이웃을 방문할
때 이전에 이용한 간선과 다른 간선을 이용해야 한다.

`vector<vector<pair<int, int>>> G` 를 선언하여 `{u : {v : color of
previous edge}}` 를 저장한다.  `queue<pair<int, int>> q` 를 선언하여
`{u : color of previous edge}` 를 저장한다. `vector<vector<int>> dist`
를 선언하여 `{u : { color of previous edge, distance }}` 를 저장한다.

BFS loop 를 시작하기 전에 `q.push({0, 0}), q.push({0, 1}),
dist.push({0, 0})` 을 수행해야 한다.

BFS loop 에서 이번에 방문한 노드와 색깔을 `{u, uc}` 라 하고 방문할
이웃노드와 색깔을 `{v, vc}` 라고 하자. `uc == vc` 이면 당연히 방문할
수 없다. 또한 `dist[v][vc] != -1` 이면 이미 방문한 곳이므로 다시
방문할 필요는 없다.

BFS 를 수행해서 dist 를 채운다. `vector<int> ans` 를 선언하고
`min(dist[i][0], dist[i][1])` 를 저장한다. 이때 `dist[u][c] == -1`
이면 `u` 까지 경로가 없다는 의미이므로 선택하지 않는다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(E+V) O(V)
```
