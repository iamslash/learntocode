# Problem

[Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

# Idea

문자열 `s, p` 가 주어진다. `s` 에서 `p` 의 anagram 이
존재하는 인덱스들의 모음을 구하는 문제이다.

`int m = s.size(), n = p.size()` 를 선언한다.  `vector<int> pv` 를
선언하여 `{character of p : count of character of p}` 를
저장한다. `vector<int> sv` 를 선언하여 `s` 를 순회하면서 `n` 크기
만큼의 문자열의 `{character of s's substr : count of character of s's
substr}` 를 저장한다. `pv == sv` 이면 답에 인덱스를 추가한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
