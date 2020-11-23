# Problem

* [Unique Word Abbreviation](https://leetcode.com/problems/unique-word-abbreviation/)

# Idea

문자열들의 모음 `V[]` 가 주어진다. `V[]` 을 축약형으로 표현해서 저장하자.
문자열 `s` 가 주어지면 `s` 의 축약형이 `s` 만을 위한 것인지 검증하는 문제이다.

예를 들어 `V = ("deer", "door", "cake", "card")` 라고 하자.
사전 `M = {"d2r":"deer", "d2r":"door", "c2e":"cake", "c2d","card"}` 이다.

* `s = dear` 이면 축약형은 `d2r` 이고 이것은 `dear` 와 다른 단어를
표현하고 있기 때문에 답은 거짓이다.
* `s = cart` 이면 축약형은 `c2t` 이고 이것은 사전에 없기 때문에
답은 참이다.
* `s = cane` 이면 축약형은 `c2e` 이고 이것은 `cane` 와 다른 단어를
표현하고 있기 때문에 답은 거짓이다.
* `s = cake` 이면 축약형은 `c2e` 이고 이것은 사전에 있지만 `cake` 만을
표현하고 있기 때문에 답은 참이다.

`unorderd_multimap<string, string> ump` 을 선언하면 쉽게 해결할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
