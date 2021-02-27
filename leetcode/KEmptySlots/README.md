# Problem

[K Empty Slots](https://leetcode.com/problems/k-empty-slots/)

위치 `p` 에 대해 개화하는 날짜 `d` 를 표현한 `pos[]` 와 숫자 `k` 가 주어진다.
즉, `pos[p] = d` 이다. 두개의 꽃이 개화할 때 그 사이에 개화되지 않는 `k` 개의
꽃이 있을 때의 날짜를 구하는 문제이다.

# Idea

예를 들어 `bulbs = [1,3,2], k = 1` 의 경우를 살펴보자.

`days[]` 를 선언하여 전구가 켜지는 날짜 (1-indexed) 를 저장해보자.
`k` 만큼 연속되게 꺼진 전구가 발견된 날짜를 구해야 한다. `k` 크기의
sliding window 를 만들어 이동한다. sliding window 를 이동하면서
`k` 만큼 연속되게 꺼진 전구가 발견된 날짜중 가장 빠른 날짜를 구한다.

```
bulbs: 1 3 2
       l   r
 days: 1 3 2
         i
```

따라서 답은 `2` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
