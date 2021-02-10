# Problem

[Maximum Absolute Sum of Any Subarray](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)

수열 `A[]` 가 주어진다.

# Idea

예를 들어 `nums = [1,-3,2,3,-4]` 의 경우를 살펴보자.

```
nums: 1 -3 2 3 -4
  ps: 1 -2 0 3 -1
```

maxPs 와 minPs 의 차이가 곧 답이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```
