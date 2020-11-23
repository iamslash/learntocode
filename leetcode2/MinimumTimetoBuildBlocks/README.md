# Problem

[Minimum Time to Build Blocks](https://leetcode.com/problems/minimum-time-to-build-blocks/)

블록을 건설하는데 필요한 비용의 모음 `B[]`, 일꾼을 복제하는데 드는
비용 `split` 주어진다. 한명의 일꾼은 하나의 블록을 건설할 수 있다.
일꾼을 복제하는데 `split` 만큼 비용이 필요하다. 일꾼은 최초 1 명
주어진다. 모든 블록을 건설하는데 필요한 최소비용을 구하라.

# Idea

예를 들어 `blocks - [1, 2], split = 5` 의 경우를 살펴보자.

```
blocks: 1 2
worker: .

worker: 1 2   5
blocks: . .

1 + 1 + 5        
```

따라서 답은 `7` 이다.

`priority_queue<int> pq` 를 선언하고 `B[]` 를 모두 저장한다. 이때
`-B[i]` 를 저장해야 가장 적은 비용을 꺼낼 수 있다. 가장 적은 비용 2
개를 꺼내어 `a, b (a > b)` 라고 하자. 새로운 비용 `-(split + b)` 를
다시 `pq` 에 저장한다. 모든 비용이 merge 되었을 때 마지막에 남은
비용이 최소 비용이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
