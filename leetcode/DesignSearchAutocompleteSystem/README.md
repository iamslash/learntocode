# Problem

> [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system/)

문자열들의 모음 `S[]` 와 출현횟수의 모음 `T[]` 가 주어진다.  한문자
`c` 를 입력받았을 때 마다 자동완성하는 시스템을 구현하는 문제이다.

# Idea

Trie 를 구성하여 해결한다.

`c` 가 `#` 이면 지금까지 입력받았던 문자열 `prefix` 를 출현횟수 `1` 로
해서 시스템에 삽입한다.

`c` 가 `[a-z]` 혹은 `' '` 이면 `prefix` 에 추가한다. `prefix` 가 Trie
에서 검색되지 않더라도 `#` 이 입력되면 `prefix` 를 Trie 에 삽입해야
하므로 `prefix` 를 유지해야 한다.

`prefix` 가 Trie 에 존재한다면 해당 문자열들을 priority_queue 에
삽입하고 상위 3 개를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
 ctor: O(K*L)
input: O(MlgM)
```
