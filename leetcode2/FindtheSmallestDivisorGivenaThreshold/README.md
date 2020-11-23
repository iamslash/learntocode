# Problem

[Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)

# Idea

숫자들의 모임 `A[]`, 숫자 threshold 가 주어진다. 어떠한 숫자 `k` 가
있을 때 `A[i]` 를 모두 `k` 로 나눈 몫의 합이 `threshold` 보다 작거나
같을 때 가장 큰 `k` 를 구하는 문제이다.

영역이 주어지고 무언가를 찾는 문제는 [binary
search](/fundamentals/search/binarysearch/README.md) 로 해결할 만
하다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(lgN) O(1)
```
