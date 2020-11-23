# Problem

[Remove Zero Sum Consecutive Nodes from Linked List](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

# Idea

싱글 링크드 리스트의 헤드노드 `h` 가 주어진다.  합이 0 이 되는
노드들을 짝지어 제거하고 남은 리스트를 구하는 문제이다.

예를 들어 `h = [1, 2, -3, 3, 1]` 을 살펴보자. `[1, 2, -3]` 을 짝지어
지울 수 있으니 답은 `[3, 1]` 이다.

먼저 dummy node `d` 를 하나 만들어 `d->next = h` 를 수행하자.

그리고 `unordered_map<int, ListNode*> sum2node = {{0, d}}` 를 선언하여
링크드 리스트를 순회하면서 `{sum of values, node pointer}` 를
저장하자. 만약 이번에 방문하는 노드의 값까지 더한 `sum` 이 `sum2node`
에 이미 있다면 제거 대상을 찾은 셈이다.

```
          d h   u
       h:   1 2-3 3 1
sum2node: 0 1 3 0
```

`v = sum2node[sum], p = v` 를 수행하고 `v` 를 하나씩 전진하여 `v != u`
인 동안 `sum2node` 에서 합을 제거한다. 반복을 마치면 `p->next =
u->next` 를 수행하여 노드들을 제거한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
