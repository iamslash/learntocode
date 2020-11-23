# Problem

[Path With Maximum Minimum Value](https://leetcode.com/problems/path-with-maximum-minimum-value/)

# Idea

그래프 `G[][]` 가 주어진다. `G[0][0]` 에서 출발하여 셀의 값이 가장 큰
셀을 경로로 하여 `G[h-1][w-1]` 에 도착해 보자. 이때 경로를 구성하는
셀의 값들 중 가장 작은 것을 구하는 문제이다.

[djikstra algorithm](/fundamentals/graph/dijkstra/README.md) 
으로 해결할 만 하다.

`priority_queue<tuple<int, int, int>> pq` 를 선언하고 `{value, y, x}`
를 저장한다. 제일 큰 값의 셀을 경로로 해야 한다. 따라서 `pq.top()` 를
다음노드로 선택해서 `G[h-1][w-1]` 까지 탐색한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
