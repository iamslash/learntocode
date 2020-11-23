# Problem

[String Transforms Into Another String](https://leetcode.com/problems/string-transforms-into-another-string/)

문자열 `s, t` 가 주어진다. `s` 의 문자 한종류를 다른 문자로 바꾼다.
`t` 가 될 수 있는지 검증하라.

# Idea

예를 들어 `s = "aabcc", t = "ccdee"` 의 경우를 살펴보자.
바꾸는 순서가 아주 중요하다.

```
aabcc
aabee
ccbee
ccdee
-----
ccdee
```

`s` 의 한문자를 바꿀때 바뀐 문자는 `s` 에 없어야 한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
