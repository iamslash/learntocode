# Problem

[Minimum Swaps to Group All 1's Together](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/)

`0, 1` 로만 구성된 수열 `A[]` 가 주어진다. `A[]` 의 임의의 위치에서 연속된
`1` 로 만들기 위해 최소의 숫자로 교체했을 때 그 숫자를 구하는 문제이다.

# Idea

예를 들어 `A = [1, 0, 1, 0, 1]` 을 살펴보자. 어딘가 연속된 1 을
만들기 위해 `0` 의 숫자가 최소인 곳을 찾으면 된다.

먼저 `int slide` 를 선언하여 숫자 `1` 의 개수를 저장한다. `slide` 만큼
윈도우를 만들어 이동시키자.  `int onecnt = 0` 를 선언하여 `1` 의
개수가 최대일 때를 저장하자. 모든 순회를 마치면 `slide - onecnt` 가
답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
