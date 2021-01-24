# Problem

[Integer Break](https://leetcode.com/problems/integer-break/)

숫자 `n` 이 주어진다. `n` 을 2 개 이상의 숫자들의 합으로 나누어
보자. 그 숫자들의 곱이 최대가 되도록 했을 때 그 곱을 구하라.

# Recursive Dynamic Programming

## Idea

## Implementation

* [c++11](recursive.cpp)
* [java8](Solution.java)

## Complexity

```
O(N^2) O(N)
```

# Iterative Dynamic Programming

## Idea

[coin change](/leetcode/CoinChange/README.md) 와 비슷한 문제이다.

`vector<int> C(n+1)` 을 선언한다. `C[0] = C[1] = 1` 을 수행한다.
`C[sum]` 에 합이 `sum` 인 숫자들의 최대곱을 저장한다.  그리고 다음과
같은 dynamic programming equation 을 발견할 수 있다.

```
C[sum] = max(C[sum], max((sum-i)*i, C[sum-i]*i))
```

## Implementation

* [c++11](iterative.cpp)
* [java8](Solution.java)

## Complexity

```
O(N^2) O(N)
```
