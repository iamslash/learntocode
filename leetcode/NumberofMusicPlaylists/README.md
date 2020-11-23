# Problem

* [Number of Music Playlists](https://leetcode.com/problems/number-of-music-playlists/)

# Idea

`N` 개의 음악이 주어지면 `L` 개의 플레이 리스트를 만들 수 있는 경우의
수를 구하는 문제이다. 단, `N` 개의 음악은 최소한 1 번은 재생되야 하고
`K` 개의 서로 다른 노래가 재생되면 반복 재생이 가능하다. 그리고 `0 <= K < N <= L <= 100` 이다.

어렵다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NL) O(N)
```
