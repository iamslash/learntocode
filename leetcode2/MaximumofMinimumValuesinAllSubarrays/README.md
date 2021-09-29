# Problem

[Maximum of Minimum Values in All Subarrays](https://leetcode.com/problems/maximum-of-minimum-values-in-all-subarrays/)

수열 `nums[]` 가 주어진다. `nums[]` 와 같은 길이의 수열을 `ans[]`
이라고 하자. `ans[i]` 는 `i+1` 길이의 부분수열들의 최소값들 중
최대값을 의미한다. `ans[]` 를 구하라.

# Idea

예를 들어 `nums = [0,4,1,2]` 의 경우를 살펴보자.

```
            nums: 0 1 2 4

subaray of 1 len: 0 1 2 4
     max of min : 4

subaray of 2 len: 0,4 4,1, 1,2
     max of min : 1

subaray of 3 len: 0,4,1 4,1,2
     max of min : 1

subaray of 4 len: 0,1,2,4
     max of min : 0
```

따라서 답은 `[4 1 1 0]` 이다.

일정한 구간에 대해 연산하는 문제이다. [mono stack](/doc/stack_overview.md#mono-stack) 으로 해결할 만
하다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
