# Problem

[House Robber](https://leetcode.com/problems/house-robber/)

수열 `A[]` 가 주어진다. 연속된 숫자를 선택할 수는 없다. 숫자를 선택하여
합이 최대가 되도록 하자. 최대합을 구하라.

# Idea

예를 들어, `A = [1, 2, 3, 1]` 을 살펴보자. `sum2ago` 는 `A[i-2]`
까지의 합중 최대이다. `sum1ago` 는 `A[i-1]` 까지의 합중
최대이다. `cur` 는 `A[i]` 까지의 합중 최대이다.

`cur` 는 `A[i]` 를 포함하는 것까지의 최대합과 포함하지 않는 것까지의 최대합을
비교하여 더 큰 것을 저장한다. 즉, `cur = max(sum2ago + A[i], sum1ago)` 를
수행한다.

```
                 i
      A:   1 2 3 1
    cur: 0 1 2 4 4
sum2ago: 0 0 1 2 4
sum1ago: 0 1 2 4 4
```

모든 반복을 마치면 `cur` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
