# Abstract

가중치 그래프의 경우 출발 정점이 하나 주어 지면 나머지 정점들로 방문하는 최단
거리를 계산하는 알고리즘이다. 이때 가중치는 양수이어야 한다. 음수 가중치의 경우
[bellman ford](/fundamentals/graph/bellmanford/README.md) 알고리즘을 사용할 수
있다. 가중치가 없다면 [BFS](/fundamentals/graph/bfs/README.md) 로 충분하다.

# Problem

정점과 간선의 가중치가 이차원 배열 `G[][]` 로 주어진다. 정점 `0` 에서 모든
정점들로 가는 최단거리들을 구하는 문제이다.

# Keyword

```java
List<int[]>[] adj
int dists[]
PriorityQueue<int[]> pq

     pq: [distance to u, u]
dist[u]: minimum distance from 0 to u

dists[0] = 0;
pq.offer(new int[]{0, 0});
```

# References

* [dijkstra in 2 minutes at youtube](https://www.youtube.com/watch?v=_lHSawdgXpI)
* [dijkstra video in geeksforgeeks](https://www.youtube.com/embed/gdmfOwyQlcI)
* [Network Delay Time](/leetcode/NetworkDelayTime/)

# Idea

출발 정점을 `start` 라고 하자. 우선 순위 큐 `PriorityQueue<int[]> pq` 를
정의하자. `pq` 에 `distance to u, u` 을 삽입한다. `pq` 의 꼭대기 값을 
`distance to u` 가 가장 작은 값으로 정렬한다.  

목표 정점까지의 거리 `int[] dists` 를 정의하고 `Integer.MAX_VALUE` 로
초기화한다. `dists[u]` 는 출발 정점에서 `u` 정점까지의 거리이다.
`dists[]` 는 반복문을 수행할 때마다 같은 목표 정점 일지라도 이전 보다 작은
값으로 업데이트가 된다. 출발 정점이 `0` 이라면 `dists[0]` 은 `0` 이다.

`pq` 가 비워질 때 까지 다음을 반복한다.

```java
            int[] item = pq.poll();
            int u = item[0], distU = item[1];
            if (dists[u] < distU) {
                continue;
            }
            if (u == dst) {
                return distU;
            }
            for (int[] next : adj[u]) {
                int v = next[0], costV = next[1];
                int distV = distU + costV;
                if (distV < dists[v]) {
                    dists[v] = distV;
                    pq.offer(new int[] { v, distV });
                }
            }
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(|E|lg|V|) O(|V|)
```

간선의 개수만큼 방문 하고 정점의 개수 만큼 우선순위 큐 정렬이 필요하기 때문이다.

피보나치 힙 혹은 이진 검색 트리를 이용하여 `O(|V|lg|V|)`에 구현할 수 있다.
하지만 구현이 복잡하거나 실제로 작성해 보면 속도가 더 느린 경우가 많아 쉽지
않다.
