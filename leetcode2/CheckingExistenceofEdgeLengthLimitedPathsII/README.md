# Problem

[Checking Existence of Edge Length Limited Paths II](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/)

# Idea

[disjoint set](/fundamentals/disjointset/unionfind/README.md) 를 이용하여 해결할
만 하다.

`TreeMap<Integer, int[]> distMap = new TreeMap<>()` 을 선언하여
`{distance: parent[]}` 를 저장한다. 즉, 거리를 기준으로 각 노드의
연결정보 snapshot 를 저장한다.

`Queue<int[]> pq = new PriorityQueue<int>((a, b) -> a[2] - b[2])` 를
선언하여 입력으로 주어진 `E[]` 를 거리의 오름차순으로 유지한다.

`int[] parent = new int[n]` 을 선언하여 부모 노드와 자식노드의
연결정보를 저장한다.

`pq.size() > 0` 동안 다음을 반복한다.

* `int[] top = pq.poll()` 을 수행한다.
* `int u, v, d` 를 `top[0], top[1], top[2]` 이라고 하자.
* `merge(parent, u, v)` 를 수행한다.
* `distMap.put(d, parent.clone())` 를 수행한다. 이것은 `parent[]` 의
  snapshot 을 저장한 것과 같다.

이렇게 `distMap` 을 채웠다면 다음과 같이 `query` 를 구현한다.

`limit` 보다 작은 거리의 연결을 얻어온다. 즉, `Integer lower =
distMap.lowerKey(limit)` 을 수행한다. 없다면 false 를 리턴한다.
있다면 `limit` 이하 거리의 간선이 존재한다는 의미이다. 그러나 `p, q`
가 연결되어 있는지는 아직 알 수 없다.

`pq` 를 오름차순으로 정렬해서 parent snapshot 을 만들었기 때문에
`lower` 보다 작은 것들 중 가장 큰 거리의 parent snapshot 만 확인해도
된다. 즉, `distMap` 의 key 들중 큰 key 는 작은 key 의 parent snaptshot
을 포함하기 때문이다.

이제 `lower` 에 대한 parent snapshot 을 얻어온다. 즉, `int[] parent =
distMap.get(lower)` 를 수행한다.

그리고 `p` 와 `q` 가 연결되어있는지 확인한다. 즉, `find(parent, p) == find(parent, q)`
를 리턴한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
query: O(NlgN) O(NlgN)
```
