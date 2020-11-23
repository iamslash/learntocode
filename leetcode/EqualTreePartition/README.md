# Problem

[Equal Tree Partition](https://leetcode.com/problems/equal-tree-partition/)

# Idea

트리의 루트노드 `u` 가 주어진다. 특정 간선을 경계로 각각의 누적합이
같은지 검증하는 문제이다. 트리의 값은 정수임을 유의하자. `-100000 <=
u->val <= 100000`

맵 `unordered_map<int, int> ump` 를 선언한다.  `u` 를 dfs 하면서 모든
서브트리의 합 `sum` 의 개수를 증가한다. `ump[sum]++`.

만약 누적합이 같은 간선이 존재한다면 루트노드의 `sum` 은 짝수일
것이다. 루트노드의 합 `sum == 0` 이면 `ump[0] > 1` 이어야 한다.
`ump[0] > 0` 가 아님을 주의하자. 루트노드의 합 `sum != 0` 이면
`ump[sum/2] > 0` 이어야 한다.

```
   0
  / \
-1   1
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(V+E) O(V)
```
