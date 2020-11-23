# Problem

[Convert to Base -2](https://leetcode.com/problems/convert-to-base-2/)

# References

* [Negative base @ wikipedia](https://en.wikipedia.org/wiki/Negative_base)

# Idea

숫자 `N` 이 주어지면 `-2` 진법으로 변환하는 문제이다.

다음은 `N = 13` 인 경우 `2` 진법으로 변환하는 과정이다. `remain`
을 거꾸로 하면 곧 `2` 진수 `1101` 가 된다.

```
       N: 13 6 3 1
  remain:  1 0 1 1 
quotient:  6 3 1 0 
```
 
음수 진법으로 변환할 때는 양수 진법으로 변환할 때와 비슷하다.
단지 나머지가 양수가 되도록 몫을 정해야 한다.

예를 들어 `N = 13` 인 경우를 살펴보자. `remain` 을 거꾸로 하면
 곧 `-2` 진수 `11101` 이 된다.

```
       N: 13 -6  3 -1 1
  remain:  1  0  1  1 1
quotient: -6  3 -1  1 0
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
