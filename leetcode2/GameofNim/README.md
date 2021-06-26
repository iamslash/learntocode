# Problem

[Game of Nim](https://leetcode.com/problems/game-of-nim/)

수열 `piles[]` 가 주어진다. Alice 와 Bob 이 Nim Game 을 한다. Alice 가
먼저 시작한다. Alice 가 이길 수 있는지 검증하라.

# References

* [Sprague-Grundy theorem. Nim](https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)

# Idea

이 문제는 [Sprague-Grundy
theorem. Nim](https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)
에 의하면 다음과 같이 해결할 수 있다.

`piles[i]` 를 모두 `xor` 하여 그 값이 0 보다 크면 먼저 시작한 사람이
이긴다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
