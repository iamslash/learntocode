# Problem

[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

문자열 `s` 가 주어진다. 최대 길이의 palindromic substring 을 구하라.

# Idea

`lo` 을 선언하여 longest palindromic substring 의 시작 인덱스를
저장한다. `maxLen` 을 선언하여 longest palindromic substring 의 길이를
저장한다. `lo, maxLen` 을 구하면 `s.substr(lo, maxLen)` 이 답이 된다.

인덱스 `i` 를 이용하여 `s` 의 처음부터 끝까지 순회하며 다음을 반복한다.

* `l = i, r = i` 를 선언한다. `l, r` 을 시작과 끝으로 하는 odd length
  palindromic subtring 을 찾고 `lo, maxLen` 을 업데이트 한다.
* `l = i, r = i+1` 를 선언한다. `l, r` 을 시작과 끝으로 하는 even
  length palindromic subtring 을 찾고 `lo, maxLen` 을 업데이트 한다.
  
모든 반복을 마치면 `s.substr(lo, maxLen)` 이 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
