# Problem

[Minimum Unique Word Abbreviation](https://leetcode.com/problems/minimum-unique-word-abbreviation/)

# Idea

문자열 `s` 와 문자열의모음 `dic[]` 가 주어진다. `s` 를 축약한 문자열을 `abbr`
이라고 하자. `dic[]` 의 문자열들과 매칭이 되지 않는 최소 길이의 `abbr` 를 구하는
문제이다.

다음과 같이 몇가지 예를 살펴보자.

`s = apple, dic = (blade)` 인 경우 `abbr = a4` 이다. 그러나 `abbr = 4e` 이면 `blade` 와 매칭이 되어 답이 아니다.

`s = abcde, dic = (xbcde, axcde)` 인 경우 `abbr = ab3` 이다.
`s = abcde, dic = (xxcde, ayyde)` 인 경우 `abbr = ab3` 이다.
`s = abcde, dic = (xxxde, ayyye)` 인 경우 `abbr = ab3 or 3de` 이다.
`s = abcde, dic = (xxxxe, ayyyy)` 인 경우 `abbr = ab3` 이다.

`dic[]` 의 문자열들을 `s` 와 비교하여 동일한 위치의 문자가 같으면 `0` 다르면
`1` 을 표기하여 `bit[]` 를 만들어 보자.

`s = abcde, dic = (xbcde, axcde)` 인 경우 `bit[] = (10000, 01000)` 이다.
`s = abcde, dic = (xxcde, ayyde)` 인 경우 `bit[] = (11000, 01100)` 이다.
`s = abcde, dic = (xxxde, ayyye)` 인 경우 `bit[] = (11100, 01110)` 이다.
`s = abcde, dic = (xxxxe, ayyyy)` 인 경우 `bit[] = (11110, 01111)` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(???) O(???)
```
