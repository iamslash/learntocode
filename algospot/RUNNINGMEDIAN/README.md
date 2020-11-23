# Problem

[변화하는 중간값](https://algospot.com/judge/problem/read/RUNNINGMEDIAN)

# Idea

우선순위가 가장 큰 녀석이 루트에 위치하는 `max_heap`과
우선순위가 가장 작은 녀석이 루트에 위치하는 `min_heap`을 다음과 같이
제작한다.

```c++
priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
```

`i`를 `0`부터 `N-1`까지 순회하면서 다음을 수행한다. 
숫자를 얻어와서 `max_heap` 과 `min_heap` 의 크기가 같으면
`max_heap` 에 삽입한다. `min_heap` 의 크기가 `max_heap` 보다
작으면 `min_heap` 에 삽입한다. 두 힙의 크기 차이를 최대 1만큼만
차이나게 균형을 유지한다.

만약 `min_heap` 의 루트가 `max_heap` 의 루트보다 크다면
두 루트를 교체 한다. `max_heap` 의 모든 노드들은 `min_heap` 의
모든 노드들 보다 우선순위가 크거나 같음이 보장된다.

하나의 숫자가 두 힙들 중 하나에 삽입되면 `max_heap` 의 루트노드가
바로 중간 값이다. 이것을 모두 더하면 답이 된다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(NlgN)
```
