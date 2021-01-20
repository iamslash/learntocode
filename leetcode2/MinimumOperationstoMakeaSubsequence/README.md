# Problem

[Minimum Operations to Make a Subsequence](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/)

수열 `T[], A[]` 가 주어진다. `T[]` 의 수는 모두 distinct 하다.  `A[]`
는 그렇지 않다. `A[]` 의 사이사이에 얼마든지 임의의 숫자를 삽입할 수
있다. `T[]` 가 `A[]` 의 subsequence 가 되도록 숫자를 삽입해 보자. 그
수가 최소가 되도록 하자. 이때 그 최소의 수를 구하라.

# Idea

예를 들어 `target = [5,1,3], arr = [9,4,2,3,4]` 의 경우를 살펴보자.

```
9 4 2 3 4
5 9 4 2 3 4
5 9 4 1 2 3 4
```

따라서 답은 2 이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
```
