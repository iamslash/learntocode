# Problem

[Line Reflection](https://leetcode.com/problems/line-reflection/)

# Idea

좌표의 모음 `P[]` 가 주어지면 y 축과 평행한 임의의 직선에 대해 좌우가
대칭인지 검증하는 문제이다.

`P[]` 를 순회하면서 `x` 좌표들 중 최소인 것과 최대인 것을
`xmin, xmax` 에 저장한다. 모든 좌표는 `unordered_set<string> ust`
에 저장한다.

`P[]` 의 임의의 점을 `pt1`, 이것과 대칭인 점을 `pt2` 라고 하면 `x`
좌표에 대해 다음과 같은 수식이 성립한다.

```
        xmin + xmax = pt1.x + pt2.x
xmin + xmax - pt1.x = pt2.x
```

`pt2` 가 `ust` 에 존재하지 않는다면 답은 거짓이다.

# Implementation

* [c++11](a.cpp)

# Complextiy

```
O(N) O(N)
```
