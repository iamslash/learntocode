# Problem

[Binary Gap](https://leetcode.com/problems/binary-gap/)

# Idea

숫자 `N` 이 주어진다. 이진수로 표현햇을 때 `1` 과 `1` 사이의 거리가
가장 큰 것의 크기를 구하는 문제이다. `11` 의 경우는 거리가 `1` 이다.

예를 들어 `N = 22, N = 5` 인 경우의 이진수를 살펴보자.

```
// N: 22 11 5 2 1
// r:  0  1 1 0 1

// N: 5 2 1
// r: 1 0 1
```

먼저 `int ans = 0` 을 선언하여 답을 저장한다. 그리고 `int cnt = -1` 을
선언하여 거리를 저장한다. 음수로 하여 `1` 이 등장하기 전을 고려한다.

위와 같이 `while (N > 0)` 다음을 반복한다.

* `N % 2 == 1` 이면 `ans = max(ans, ++cnt), cnt = 0` 를 수행한다.
* `N % 2 == 0` 이면 `if (cnt >= 0) ++cnt` 를 수행한다.
* `N /= 2` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
