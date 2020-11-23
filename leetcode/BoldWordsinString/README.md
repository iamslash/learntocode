# Problem

* [Bold Words in String](https://leetcode.com/problems/bold-words-in-string/)

# Idea

문자열들의 리스트 `W` 와 문자열 `s` 가 주어진다.
`W` 의 문자열들이 `s` 에 존재하면 `<b></b>` 로 감싼다.
이때 겹치는 부분은 병합된 문자열을 구하는 문제이다.

다음과 같이 `vector<bool> bolds` 를 선언한다. 인덱스 `i`
를 이용하여 `W` 를 순회한다. `W[i]` 가 `s` 에 존재하면
점유하는 만큼 `bolds[]` 를 `true` 로 채운다.

`bolds[]` 를 순회하면서 문자열을 조합한다.



# Complexity

```
O(WS) O(S)
```

# Implementation

* [c++11](a.cpp)
