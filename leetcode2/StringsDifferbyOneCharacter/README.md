# Problem

[Strings Differ by One Character](https://leetcode.com/problems/strings-differ-by-one-character/)

문자열의 모음 `dict[]` 가 주어진다. 모든 문자열은 길이가 같다.  한
문자만 다른 문자열이 2 개 존재하면 true 를 리턴하라.

# Idea

`dict[]` 를 순회하면서 만나는 문자열을 `s` 라고 하자.  `s` 의 각
문자를 `*` 로 교체하면서 `s` 를 `dictMap` 에 삽입한다.

# Implementation

* [a.go](a.go)

# Complexity

```
O(NW) O(NW)
```
