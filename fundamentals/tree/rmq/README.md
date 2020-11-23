# Problem

수열 `V` 가 주어진다. 특정 구간의 최소 값을 찾는 문제이다.

* [Range Minimum Query @ hackerrank](https://www.hackerrank.com/challenges/range-minimum-query/problem)

# Idea

이러한 문제를 RMQ (range minimum query) 라고 부른다. [segment tree](/fundamentals/tree/segmenttree/README.md) 를 제작하여 해결해보자. 

![](/_img/segmenttree.png)

# Implementation

* [c++11](a.cpp)

# Complexity

```
build segment tree: O(N)   O(N)
             query: O(lgN) O(1)
```
