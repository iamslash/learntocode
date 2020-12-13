# Problem

[Partitioning Into Minimum Number Of Deci-Binary Numbers](https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/)

문자열 숫자 `n` 이 주어진다. deci binary 의 합으로 표현해 보자. 그
개수가 최소일 때 그 개수를 구하라

예를 들어 `32 = 11 + 11 + 10` 이다. 따라서 답은 3 이다.

# Idea

greedy algorithm 으로 해결할 만 하다.

예를 들어 `32` 를 살펴보자.

```
32
---
11
11
10   
```

`n` 을 구성하는 자리수중 가장 큰 수가 곧 deci binary 의 개수를
의미한다.

# Implementation

* [c++11](a.cpp)
* [java8](a.java)
* [py3](a.py)

# Complexity

```
O(N) O(1)
```
