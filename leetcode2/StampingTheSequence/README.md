# Problem

[Stamping The Sequence](https://leetcode.com/problems/stamping-the-sequence/)

문자열 `stamp`, `target` 이 주어진다.  `target` 에서 `stamp` 에
해당하는 문자열을 마킹한다. `target` 에서 마킹된 부분은 `stamp` 의
어느 문자와도 매칭된다. 최소의 횟수로 `target` 을 모두 마킹해
보자. `stamp` 가 시작되는 `target` 의 위치를 모두 리턴하라.

# Idea

예를 들어 `stamp = "abc", target = "ababc"` 의 경우를 살펴보자.

```
 stamp: a b c
target: a b a b c
            * * *
        * * *
            
[0, 2]
```

greedy algorithm 으로 해결할 만 하다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(T^2S) O(T)
```
