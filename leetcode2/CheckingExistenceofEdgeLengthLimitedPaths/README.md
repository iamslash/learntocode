# Problem

[Checking Existence of Edge Length Limited Paths
](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)

숫자 `n`, 간선의 모음 `E[]`, 질의 `Q[]` 가 주어진다.  `n` 개의 노드를
갖는 그래프가 있다. `E[0], E[1], E[2]` 는 각각 시작노드, 종료노드,
거리를 의미한다. `Q[0], Q[1], Q[2]` 는 각각 시작노드, 종료노드, 한계를
의미한다.

`Q[]` 를 순회하면서 다음의 결과들의 모음을 구하라.
* `Q[0]` 노드에서 출발하여 `Q[1]` 노드까지 탐색해 보자. 임의의 간선
  한개의 거리가 `Q[2]` 보다 작으면 `true` 를 리턴한다. 그렇지
  않다면 `false` 를 리턴한다.

# Idea

예를 들어 `n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]],
queries = [[0,1,2],[0,2,5]]` 의 경우를 살펴보자.

```
max of optimized dist(0 -> 1) = 2
max of optimized dist(0 -> 1 -> 2) = 4
```

따라서 답은 `[false, true]` 이다.

간선들의 거리가 `Q[i][2]` 보다 작은 것들을 모아 놓았다고 해보자.
그렇다면 `Q[i][0], Q[i][1]` 가 같은 모임에 속해 있는지 검증하면 된다.

[Disjoint Set @ learntocode](/fundamentals/disjointset/unionfind/README.md) 을 이용하여 간선들의 그룹을 저장한다면 해결할 만 하다.

`vector<bool> ans(Q.size())` 를 선언하여 답을 저장한다.

인덱스 `i` 를 선언하여 `[0..Q.size())` 동안 순회하면서 다음을 반복한다.
* `Q[i].push_back(i)` 를 수행한다.

`Q[i][3]` 은 `ans[]` 에서 `Q[i]` 의 인덱스를 의미한다.

`Q[]` 를 `Q[i][2]` 의 오름차순으로 정렬한다.
`E[]` 를 `E[i][2]` 의 오름차순으로 정렬한다.

`DisjointSet ds(n)` 를 선언한다.

간선의 인덱스 `int j = 0` 을 선언한다. `Q[]` 를 `q` 로 순회하면서 다음을 반복한다.

* `u = q[0], v = q[1], w = q[2]` 를 수행한다.
* `j < e.size()` 동안 다음을 반복한다.
  * `e = E[j]` 를 수행한다.
  * `e[0], y = e[1], z = e[2]` 를 수행한다.
  * `q[2]` 보다 크거나 같은 간선이 있다면 반복을 종료한다. 즉, `z >= w` 이면
    반복을 종료한다.
  * `x, y` 는 `q[2]` 보다 작은 거리로 연결되어 있다. 한그룹으로     합쳐도 좋다.
    즉, `ds.merge(x, y)` 를 수행한다.
* 이제 `u, v` 가 한그룹인지 조사한다. 즉, `ans[q[3]] = ds.connected(u, v)` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(ElgE) O(N)
```
