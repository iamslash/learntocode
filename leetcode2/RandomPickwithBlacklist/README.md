# Problem

[Random Pick with Blacklist](https://leetcode.com/problems/random-pick-with-blacklist/)

숫자 `N` 과 숫자의 모음 `blackList[]` 가 주어진다.  `[0..N)` 영역의
숫자중 `blackList[]` 에 속하지 않은 숫자를 random 하게 리턴하라.

# Idea

Do not use `random()` in C++11. [Random Number Generation in
C++11](https://isocpp.org/files/papers/n3551.pdf)

예를 들어 `N = 10, blackList = [3, 5, 7, 9]` 의 경우를 살펴보자.

```
        N: 10
blackList: 3 5 7 9

1 2 3 4 5 | 6 7 8 9
    8   6

 blackMap: 3 5 7 9
           8 6 - -
whitesize: 6
```

`[0..N)` 의 숫자들 중 `blackList[]` 에 속한 숫자들은 뒤쪽으로 모아
놓는다. 그렇다면 앞쪽의 숫자들 중 랜덤하게 하나 고르면 된다.

`int whiteSize` 를 선언하여 앞쪽 숫자들의 크기를 저장한다.
`unordered_map<int, int> blackMap` 을 선언하여 랜덤하게 선택한 숫자가
`blackList` 에 속한다면 대신 사용할 숫자를 저장한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
