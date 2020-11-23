# Problem

[Last Substring in Lexicographical Order](https://leetcode.com/problems/last-substring-in-lexicographical-order/)

문자열 `s` 가 주어진다. `s` 의 substring 중 사전순으로 가장 나중에
위치하는 substring 을 구하라.

# Idea

모두 같은 문자인지 검사해 보고 그렇다면 `s` 가 답이다.

`substr` 를 사용하면 time complexity 가 증가하므로
`lexicographical_compare` 를 이용한다.


# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NS), O(1)
```
