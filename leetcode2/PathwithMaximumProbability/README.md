# Problem

[Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)

숫자 `n, start, end` 와 간선의 모음 `E[][]`, 그리고 확률의 모음 `P[]`
가 주어진다.  `n` 만큼의 노드가 있고 시작 노드는 `start`, 종료 노드는
`end` 이다.  `start` 에서 출발하여 `end` 로 가는 길을 찾는다. 이때
경로에 해당하는 간선의 확률을 곱한다.  확률이 최대가 되는 경로를 찾고
그 최대 확률을 구하라.

# Idea

[dijkstra](/fundamentals/graph/dijkstra/README.md) 를 이용하여 해결할 만 하다.

`vector<unordered_map<int, double>> G` 를 선언하여 `E[][], P[]` 를 저장한다.

`vector<int> ans(n, 0.0)` 를 선언하여 노드별 도착 확률을 저장한다. 이때 `ans[start] = 1.0` 으로 초기화 해야 한다.

`queue<int> q` 를 선언하고 BFS queue 로 이용한다. 이때 `q.push(start)` 으로 초기화 해야 한다.

이제 `start` 에서 출발하여 `end` 까지 BFS 하면서 `ans` 를 업데이트 한다.

모든 반복을 마치면 `ans[end]` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(V)
```
