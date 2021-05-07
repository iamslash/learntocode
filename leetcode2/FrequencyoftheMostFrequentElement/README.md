# Problem

> [Frequency of the Most Frequent Element](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)

수열 `A[]`, 숫자 `k` 가 주어진다. 최대 `k` 만큼 임의의 숫자를 선택해 1
씩 증가할 수 있다. `A[]` 에서 최대로 반복될 수 있는 숫자를 찾아서 그
반복횟수를 구하라.

# Idea

예를 들어 `nums = [1,2,4], k = 5` 를 살펴보자.

``` 
 nums: 1 2 4
 goal: 4 4 4
delta: 3 2 0
```

따라서 답은 `3` 이다.

sliding window 로 해결할 만 하다. 1 씩 증가할 수 있다고 했으니 `goal`
에 해당하는 숫자는 처음 주어진 `A[]` 중 하나이다. `A[]` 를
오름차순으로 정렬한다. 그러면 `goal` 의 후보는 `A[i]` 가 된다.

`int sum = 0` 을 선언하여 window 에 포함된 `A[i]` 의 합을 저장한다.
`sum <= goal * k` 를 만족해야 한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(1)
```
