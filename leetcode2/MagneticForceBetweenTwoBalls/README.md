# Problem

[Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/)

수열 `P[]`, 숫자 `m` 이 주어진다. `m` 개의 공을 적당히 배치해서 서로의
간격이 최소한 `bnd` 이상이 되게 하자. `P[i]` 는 공이 놓여질
위치이다. 최대의 `bnd` 를 구하는 문제이다.

# Idea

예를 들어, `P = [1, 2, 3, 4, 7], m = 3` 의 경우를 살펴보자.  `bnd` 를
선언하여 공의 최소 간격을 저장한다. `[1..999999999]` 에서 binary
search 한다.

```
  m: 3
  P: 1 2 3 4 7
     l                h
bnd: 1 2 3 .. 999999999
            m
```

[binary search with array @ learntocode](/fundamentals/search/binarysearch/README.md)

# Implementation

* [go](a.go)

# Complexity

```
O(NlgN) O(1)
```
