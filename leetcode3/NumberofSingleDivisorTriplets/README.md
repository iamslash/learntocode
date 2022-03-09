# Problem

[Number of Single Divisor Triplets](https://leetcode.com/problems/number-of-single-divisor-triplets/)

수열 `nums[]` 가 주어진다. 서로 다른 3 개의 인덱스 `(i, j, k)` 를
찾는다.  `nums[i] + nums[j] + nums[k]` 를 `nums[i], nums[j], nums[k]`
중 하나로만 나누어 떨어져야 한다. 그 가짓수를 구하라.

# Idea

문제의 조건에 의해 `1 <= nums[i] <= 100` 이다. 범위에 해당하는 숫자만
살펴보자.

`int ans = 0` 을 선언하여 답을 저장한다.  `int[] freqs = new int[101]`
를 선언하여 `nums[i]` 의 출현 횟수를 저장한다.

답을 구하기 위해 다음과 같이 2 가지의 경우를 따져본다.

```
두개의 숫자만 같은 경우 `a, a, b`. `a, a, b` 를 배치하는 방법은 3 가지이다.

ans += 3L * freqs[a] * (freqs[a]-1) * freqs[c]

서로 다른 숫자의 경우 `a, b, c`. `a, b, c` 를 배치하는 방법은 6 가지이다.

ans += 6L * freqs[a] * freqs[b] * freqs[c]
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(1) O(1)
```
