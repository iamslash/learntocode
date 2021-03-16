# Problem

[Number of Restricted Paths From First to Last Node](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/)

숫자 `n`, 간선의 모음 `E[][]` 가 주어진다. `n` 개의 노드가 있고 `n` 은
`1-indexed` 이다. 즉, `[1..n]` 의 노드가 있다.  `E[i][0], E[i][1],
E[i][2]` 는 출발 노드, 도착 노드, 비용을 의미한다.

`distanceToLastNode(x)` 를 `x` 노드에서 `n` 노드까지의 거리라고 하자.

`1` 노드에서 `n` 노드까지 임의의 경로가 있을 때 그것을 `[z_0, z_1,
..., z_k]` 라고 표현해 보자. 이때 `distanceToLastNode[z_k-1] >
distanceToLastNode[z_k]` 를 보장하는 경로들을 구하라.

`1` 노드에서 출발하여 `n` 노드에 도착하는 경로들을 구해야하는 것을
주의 하라.

# Idea

먼저 [dijkstra](/fundamentals/graph/dijkstra/README.md) 를 이용하여 `dist[]` 에 임의의 노드 `u` 에
대하여 `distanceToLastNode(u)` 를 저장한다.

이제 [DFS](/fundamentals/graph/dfs/README.md) 를 이용하여 `1` 노드부터 `n` 노드까지
`distanceToLastNode(z_k-1) > distanceToLastNode[z_k]` 를 보장하는
경로들의 개수를 구한다.

# Implementation

* [python3](a.py)

# Complexity

```
O(E*lgV) O(E+N)
```
