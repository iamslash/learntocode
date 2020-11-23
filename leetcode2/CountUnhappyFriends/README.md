# Problem

[Count Unhappy Friends](https://leetcode.com/problems/count-unhappy-friends/)

숫자 `n` 과 취향의 모음 `preferences[][]`, 짝의 모음 `pairs[][]` 가
주어진다. `n` 명의 친구들이 있다. `preferences[u]` 는 리스트이고 `u`
하고 가까운 순서대로 놓여있다. `pairs[i][0], paris[i][1]` 는 서로 짝이
맺어진 친구 둘을 의미한다.

`pairs[][]` 중에 서로 사이가 가깝지 않은 짝은 unhappy 하다고 하자.
unhappy 한 친구들이 몇명인지 구하라.

문제의 내용이 명확하지 않다. 다음을 유의하자.

When 

* `x` prefers `u` over `y`, and
* `u` prefers `x` over `y`

Then

* Both `x` and `u` are unhappy. Not just `x`.

# Idea

It's hard to understand the problem.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
