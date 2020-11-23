# Problem

[Longest Duplicate Substring](https://leetcode.com/problems/longest-duplicate-substring/)

문자열 `s` 가 주어진다. 두번 이상 반복되는 문자열들 중
길이가 가장 큰 것을 구하라.

# Idea

`string rabinkarp(string s, int len)` 정의하여 `s` 에서 길이가 `len`
이면서 두번 이상 반복되는 문자열을 리턴하도록 한다.

이제 `len` 을 `[0..n)` 의 범위에서 [binary search](/fundamentals/search/binarysearch/README.md) 한다.
binary serach loop 에서 `rabinkarp(s, mi)` 를 이용하여 중복되는 문자열을 찾는다. 찾았다면 `len` 을 증가시킨다.
찾지 못했다면 `len` 을 감소한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
