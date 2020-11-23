# Problem

[Minimum Window Subsequence](https://leetcode.com/problems/minimum-window-subsequence/)

# Idea

문자열 `S, T` 가 주어진다. `S` 의 연속된 부분 문자열을 `W` 라고 하자.
`W` 들 중 일부 문자들을 지웠을 때 `T` 와 같다. 길이가 제일 작은 `W` 를
구하는 문제이다.

dynamic programming 을 이용하여 해결한다.  예를 들어 `S = "abcdebdde",
T = "bde"` 의 경우 2 차원 캐시는 다음과 같다.

```
  0 a b c d e b d d e
0 1 2 3 4 5 6 7 8 9 10
b 0 0 2 2 2 2 6 6 6 6
d 0 0 0 0 2 2 2 6 6 6
e 0 0 0 0 0 2 2 2 2 6
```

2 차원 캐시를 모두 채우고 나면 마지막 행을 처음부터 순회하여 인덱스
`beg`, 길이 `len` 을 이용하여 `W` 를 만들어낼 수 있다. `W` 을 제작하지
못한다면 "" 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(W)
```
