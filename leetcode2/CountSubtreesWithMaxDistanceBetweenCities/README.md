# Problem

[Count Subtrees With Max Distance Between Cities](https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/)

노드의 개수 `n`, 간선의 모음 `E[][]` 가 주어진다. `E` 의 개수는 `n-1`
이다. 즉, node 들은 tree 를 구성한다. `1 <= d <= n-1` 라고
정의하자. `ans[n-1]` 를 선언한다. 임의의 node 들 간의 최대 거리가 `d`
가 되는 subtree 의 개수들을 `ans[d-1]` 에 저장한다. `ans` 를 구하라.

# Idea

[floyd warshall](/fundamentals/graph/floyd/README.md) 을 사용하여 `G[][]` 에 모든 node 사이의 최소 거리를
저장한다.

문제의 조건에 의해 `2 <= n <= 15` 이다. node 들이 포함된 상황을 bit
mask 에 저장할 수 있다.

`bm = 0` 을 선언하여 `bm < (1 << n)` 인 동안 순회하며 다음을 반복한다.

* `nodeCnt` 을 선언하고 node 의 개수를 저장한다. 즉, `bm` 에서 bit 1
  의 개수를 저장한다.
* `edgeCnt` 를 선언하여 node 사이의 거리가 1 인 간선의 개수를
  저장한다. `edgeCnt == nodeCnt - 1` 이면 하나의 subtree 를 구성한다고
  말할 수 있다.
* `maxDist` 를 선언하여 `nodeCnt` 개수의 subtree 가 구성되었을 때
  임의의 node 들의 최대 거리를 저장한다.
* `edgeCnt == nodeCnt - 1` 이고 `maxDist > 0` 이면 `ans(maxDist - 1]`
  를 하나 증가한다.
  
모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3) O(N^2)
```
