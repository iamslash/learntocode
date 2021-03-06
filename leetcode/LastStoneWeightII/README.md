# Problem

[Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/)

# Idea

돌의 무게의 모임 `S[]` 가 주어진다. 두개의 돌을 짝지어 보자.  각각
무게를 `x, y` 라고 하자. `x <= y` 일 때 `x == y` 이면 두개의 돌은
없어진다.  그러나 `x != y` 일 때 `y - x` 의 돌만 남는다. 두개의 돌을
짝지어 제거했을 때 가장 마지막에 남는 돌의 무게가 가장 적도록
해보자. 그 때의 무게를 구하는 문제이다.

예를 들어 `S = [2, 7, 4]` 인 경우를 살펴보자. 돌을 서로 짝지어
만들 수 있는 모든 조합을 생각해 보자.

| stage | proc | value |
:-------|:-----|:------|
| 0     | -2 +2 | -2 +2 |
| 1     | -2-7 -2+7 2-7 2+7 | -9 +5 -5 +9 | 
| 2     | -2-7-4 -2-7+4 -2+7-4 -2+7+4 2-7-4 2-7+4 2+7-4 2+7+4 | -13 -5 +1 +11 -11 -1 5 15 |

2 단계에서 만들어진 value 들 중 절대값이 가장 작은 것 `(-2+7-4, 2-7+4)` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(2^N) O(2^N)
```
