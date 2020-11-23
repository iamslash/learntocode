# Problem

[All Paths from Source Lead to Destination](https://leetcode.com/problems/all-paths-from-source-lead-to-destination/)

# Idea

노드의 개수 `n`, 간선의 정보 `E[]`, 출발지 노드 `src`, 목적지 노드
`dst` 가 주어진다. `src` 에서 `dst` 로 다음과 같은 규칙을 만족하는
경로가 최소한 하나 있는지 검증하는 문제이다.

* `src` 에서 `v` 노드로 진행했을 때 `v` 노드에서 나가는 간선이 없다면
  `v` 는 `dst` 이어야 한다.
* cycle 이 없어야 한다.

DFS 로 해결한다. `vector<int> seen(n, -1)` 을 선언하여 노드가 방문하기
전이면 `-1`, 방문하고 처리중이면 `0`, 방문을 마치고 `src` 에서 `dst`
로 가는 경로를 최소한 하나 찾았다면 `1` 을 저장한다.

DFS loop 전에 `seen[u] = 0` 을 수행하고 DFS loop 가 모두 끝나면
`seen[u] = 1` 를 수행한다.

# Implmentation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
