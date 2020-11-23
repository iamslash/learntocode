# Problem

[Moving Stones Until Consecutive](https://leetcode.com/problems/moving-stones-until-consecutive/)

# Idea

좌표 `x, y, z` 가 주어진다. 3 개의 돌이 `x, y, z` 위치에
놓여있다. 양쪽 돌중 하나만 집어서 최초 `x, z` 사이에 둘 수 있다.  3
개의 돌이 서로 나란히 되도록 하기 위한 최소 움직임수와 최대 움직임수를
구하는 문제이다.

예를 들어 `x=1, y=2, z=5` 의 경우를 살펴보자.

```
a b     c
1 2 3 4 5
```

* `c` 를 `3` 에 놓는다. 따라서 최소 움직임수는 `1` 이다.
* `a` 를 `4` 에 놓고 `c` 를 `3` 에 놓는다. 따라서 최대 움직임수는 `2` 이다.

`x < y < z` 가 되도록 정렬한다. 그리고 다음과 같은 경우를 생각해 보자.

* `z - x` == 0 이면 `[0, 0]` 가 답이다.
* 두개의 돌이 붙어 있거나 두개의 돌 사이에 하나의 공간이 있다면 최소
  움직임 수는 1 이다. 그렇지 않다면 최소 움직임수는 2 이다.
* 최대 움직임수는 `z - x - 2` 와 같다.

# Implementation

* [java8](Solution.java)

# Complexity

```
```
