# Problem

> [Binary Tree Longest Consecutive Sequence](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)

트리의 루트노드가 주어진다. 노드의 값이 연속이고 오름차순인
것들의 최대 개수를 구하라.

# Idea

다음과 같은 부분문제 `dfs` 를 정의한다.

```
int dfs(u)

return: local max count of the path which starts with u
     u: this node
```

다음과 같은 변수를 선언한다.

> * `glbMax = 0`: 답

`dfs` 의 `base` 를 구현한다.

> * `u == null` 이면 `0` 을 리턴한다.

`dfs` 의 `recursion` 을 구현한다.

> * `int l = dfs(u.left) + 1` 를 수행한다.
> * `int r = dfs(u.right) + 1` 를 수행한다.
> * `u.val` 이 `u.left` 보다 하나 작으면 연속이다. 그렇지 않으면
>   연속이 아니다. 연속이 아니면 `l = 1` 를 수행한다.
> * `u.val` 이 `u.right` 보다 하나 작으면 연속이다. 그렇지 않으면
>   연속이 아니다. 연속이 아니면 `r = 1` 를 수행한다.
> * `locMax = Math.max(l, r)` 를 수행한다.
> * `glbMax` 를 업데이트 한다.
> * `locMax` 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(lgN)
```
