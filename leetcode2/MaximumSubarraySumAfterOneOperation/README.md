# Problem

[Maximum Subarray Sum After One Operation](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/)

음수, 양수로 구성된 수열 `A[]` 이 주어진다. 하나의 숫자를 제곱할 수
있다.  sub array 들 중 합이 최대인 것을 구하라.

# Idea

이번 숫자를 포함해서 계산한 경우와 이번 숫자를 포함하지 않고 계산한
경우를 나누어서 생각해 본다. [kadane's algorithm](/fundamentals/array/kadane/README.md) 과 비슷하다.

`int ans = 0` 를 선언하여 하나의 숫자를 제곱한 sub array 들 중 합이
최대인 것의 합을 저장한다. `int onOps = 0` 를 선언하여 지금까지 검토한
sub array 들 중 하나의 숫자를 제곱한 것의 최대합을 저장한다. `int
noOps = 0` 를 선언하여 지금까지 검토한 sub array 들 중 하나의 숫자를
제곱하지 않은 것의 최대합을 저장한다.

예를 들어 `A = [2,-1,-4,-3]` 인 경우를 살펴보자.

```
    A: 2 -1 -4 -3
onOps: 4  3 17 14  
noOps: 2  1  0  0
  ans: 4  4 17 17
```

따라서 답은 `17` 이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
