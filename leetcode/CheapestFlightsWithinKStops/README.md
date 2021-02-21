# Problem

[Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

출발지, 목적지, 거리들의 모음 `E[]` 와 숫자 `src, dst, k` 가 주어진다.
`src` 를 출발하여 `k` 만큼의 노드를 경유하고 `dst` 까지 도착하는데
걸리는 최소 비용을 구하는 문제이다.

# Idea

하나의 출발지에서 목적지까지 걸리는 최소 비용을 구하는 문제이다.
[dijkstra algorithm](/fundamentals/graph/disjkstra/README.md) 과
`dst, k` 를 제외하고 거의 비슷하다. 

우선 순위 큐 `priority_queue<tpule<int, int, int>> pq` 를 정의하고
`거리, 도착지, 남은k` 를 삽입한다. 이때 거리는 `-1` 을 곱해야 가장
적은 거리가 우선순위가 높아진다.

`pq.push({0, src, k+1})` 하고 `while (pq.size())` 동안 다음을 반복한다.

* `pq` 에서 아이템을 하나 뽑아내어 `거리, 노드, 남은k` 를 `dist, u,
   ttl` 에 저장한다.
1. 도착했으면 `dist` 를 리턴한다.
2. `ttl > 0` 이면 이웃들을 `pq` 에 삽입한다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(ElgV) O(V)
```
