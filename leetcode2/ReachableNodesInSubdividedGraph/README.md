# Problem

[Reachable Nodes In Subdivided Graph](https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/)

간선의 모음 `E[][]`, 숫자 `M, N` 이 주어진다. `N` 개의 node 와 `E[][]`
의 간선을 갖는 그래프가 있다. `E[i][0]` node 에서 `E[i][1]` node 까지
`E[i][2]` 개의 노드를 삽입한다. 그리고 `0` 번 node 에서 출발하여 최대
`M` 만큼 움직일 수 있을 때 도착할 수 있는 모든 node 의 개수를 구하라.

# Idea

먼저 `int[][] G = new int[N][N]` 를 선언하고 `-1` 로 초기화 한다.
`G[u][v]` 는 `u` node 에서 `v` node 사이에 삽입할 node 의 개수를
의미한다.

`Queue<int[]> pq = new PriorityQueue<>((a,b) -> (b[1] - a[1]))` 를
선언하여 BFS queue 로 활용한다. `boolean[] visit = new boolean[N]` 를
선언하여 node 의 방문여부를 저장한다.

`0` node 에서 `M` 만큼의 capacity 로 출발한다. 즉, `pq.offer(new
in[]{0, M})` 를 수행한다. 

`u` node 에서 `c` capacity 를 가지고 `v` node 로 간다고 해보자. 중간의
node 들의 개수가 `c` 보다 작으면 `v` 부터 다시 출발할 수 있다. 즉,
`pq.offer(new int[]{v, c - G[u][v] - 1)` 를 수행한다. 중간의 node 들의
개수가 `c` 보다 크거나 같으면 `v` 까지는 갈 수 없고 `min(c, G[u][v])`
를 `ans` 에 더한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(VlgV) O(V)
```
