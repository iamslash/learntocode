# Problem

[Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

수열 `target[]` 이 주어진다. `target.size()` 와 개수가 같고 `1` 로 구성된
수열 `I[]` 가 있다고 하자. `I[]` 는 다음과 같은 규칙의 연산을 할 수 있다.

* `I[]` 의 모든 합 `sum` 을 `I[i]` 에 저장할 수 있다.

`I[]` 가 `target[]` 이 될 수 있는지 검증하라.

# Idea

예를 들어 `target = [9, 3, 5]` 의 경우를 살펴보자.

```
1 1 1
1 3 1
1 3 5
9 3 5
```

따라서 답은 true 이다.

거꾸로 생각해 보자.

```
9 3 5    9 -> 1
1 3 5    5 -> 1
1 3 1    3 -> 1
1 1 1
```

`priority_queue<int> pq` 를 선언하여 최대 값을 `O(1)` 로 꺼낼 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
