# Problem

[Numbers At Most N Given Digit Set](https://leetcode.com/problems/numbers-at-most-n-given-digit-set/)

수열 `D[]` 와 숫자 `N` 이 주어진다.  `D[]` 의 숫자들을 무수히 이용해서
`N` 보다 작거나 같은 숫자들을 만들어 보고 그 개수를 구하라.

# Idea

예를 들어 `D = ["1", "3", "5", "7"], N = 100` 의 경우를 살펴보자.

```
1
3
4
7
11 13 15 17 
31 33 35 37 
51 53 55 57
71 73 75 77
```

따라서 답은 `20` 이다.

숫자를 만들어 낼 때 시작 문자와 자리수를 고려해 보자.

* `x` 를 만들어 낸다면 모두 해당된다. 
  * 따라서 4 이다.
* `xx` 를 만들어 낸다면 모두 해당된다.
  * `1x` 4 가지
  * `3x` 4 가지
  * `5x` 4 가지
  * `7x` 4 가지
* `xxx` 는 불가능하다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(DN) O(1)
```
