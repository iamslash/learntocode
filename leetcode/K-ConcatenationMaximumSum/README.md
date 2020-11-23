# Problem

[K-Concatenation Maximum Sum](https://leetcode.com/problems/k-concatenation-maximum-sum/)

# Idea

수열 `A[]` 와 숫자 `k` 가 주어진다. `A` 를 `k` 만큼 반복했을 때
만들어진 수열의 subarray 들 중 원소들의 합이 최대일 때 그 합을 구하는
문제이다.

이것은 [Maximum Sum Circular Subarray](/leetcode/MaximumSumCircularSubarray/) 와 비슷하다.

`A` 를 `k` 만큼 반복한 수열을 `AK`, 두번 반복한 수열을 `AA` 라고 하자.

`int allsum` 을 선언하여 `A` 원소들의 합을 저장한다. `allsum` 은 `k`
만큼 반복된다. 따라서 `AK` 원소들의 합은 `allsum * k` 이다. 이제 `AK`
의 subarray 들 중 원소들의 합이 최소인 것을 `glbmin` 이라고 하자.
`allsum * k - glbmin` 이 답이다.

`glbmin` 은 `A` 가 최소로 반복되는 `AA` 에서 찾아낼 수 있다. `int
locmax, glbmax` 를 선언하고 local max sum, global max sum 을 저장한다.
`glbmin = allsum * 2 - glbmax` 이다.

따라서 `max(0, glbmax, allsum * k - glbmin)` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
