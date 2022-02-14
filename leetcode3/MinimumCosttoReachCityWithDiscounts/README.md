# Problem

[Minimum Cost to Reach City With Discounts](https://leetcode.com/problems/minimum-cost-to-reach-city-with-discounts/)

숫자 `n` , 수열의 모음 `highways[][]`, 숫자 `discounts` 가
주어진다. `0` 번 노드부터 `n-1` 번 노드까지 최단 거리를
구하라. `discounts` 개수 만큼 거리를 절반으로 줄일 수 있다.  단,
하나의 간선에만 적용할 수 있다. 가능한 경로가 없다면 `-1` 을 리턴하라.

# Idea

[dijkstra](/fundamentals/graph/dijkstra/README.md) 를 이용하여 해결할 수 있다. 

다음과 같은 차이점이 있다.

* `pq` 에 `[dist to v, v, discount]` 를 삽입한다.
* `dist[]` 대신 `dist[][]` 를 사용한다.
* 이웃노드에 해당하는 `v` 를 방문할 때 discount 를 하지 않는 경우와
  하는 경우를 모두 따져본다.

```
dist[v][d] = 

v: target node
d: discount
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(ElgV) O(V)
```
