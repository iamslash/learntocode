# Problem

* [Sum of Distances in Tree](https://leetcode.com/problems/sum-of-distances-in-tree/)

# Idea

트리의 노드들의 수 `N` 과 간선의 배열 `E` 가 주어진다.  각 노드들에서
다른 노드들까지의 거리들을 구하는 문제이다.

이차원 배열 `adj[][]` 와 일차원 배열 `rst[], cnt[]` 를 정의한다.
`rst[i]` 는 `i` 노드에서 다른 노드들까지의 거리들의 합이다.  `cnt[i]`
는 `i` 노드의 자식 노드들의 개수이다.

다음과 같은 중요한 규칙들을 발견할 수 있다.

```
cnt[root] = sum(cnt[i]) + 1
rst[root] = sum(rst[i]) + sum(cnt[i])

rst[x] = x@x + y@y + #y
rst[y] = y@y + x@x + #x
rst[x] - rst[y] = #y - #x

rst[child] = rst[parent] - cnt[child] + (N - cnt[child])
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
