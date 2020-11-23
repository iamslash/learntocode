# Problem

[Nth Magical Number](https://leetcode.com/problems/nth-magical-number/)

숫자 `N, A, B` 가 주어진다. `A` 혹은 `B` 로 나누어 떨어지는 `N` 번째
숫자를 구하라.

# Idea

예를 들어 `N = 5, A = 2, B = 4` 인 경우를 살펴보자.

```
2 4 5 8 10
```

어떤 숫자 `K` 가 주어지면 

* `A` 로 나누어 떨어지는 숫자는 `K/A` 이다.
* `B` 로 나누어 떨어지는 숫자는 `K/B` 이다.
* `gcd(A,B)` 로 나누어 떨어지는 숫자는 `K/gcd(A,B)` 이다.

이때 `A` 혹은 `B` 로 나누어 떨어지는 숫자의 개수는 `K/A + K/B -
K/gcd(A,B)` 와 같다. 이 규칙을 이용하여 [left most equal binary
search](/fundamentals/search/binarysearch/README.md) 한다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
