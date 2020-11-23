# Problem

[Longest String Chain](https://leetcode.com/problems/longest-string-chain/)

문자열들의 모음 `W[]` 가 주어진다. 특정 문자열 `a` 에서 단 하나의
문자를 임의의 위치에 삽입했을 때 문자열 `b` 가 된다면 `a->b` 를
체인이라고 하자. `W[]` 의 가장 긴 체인의 길이를 구하는 문제이다.

# Idea

`int glbmax = 0` 을 선언하여 global maximum chain count 을 저장한다.
`unordered_map<string, int> C` 를 선언하여 `{string: maximum chain
count of string` 를 저장한다.

이제 `W[]` 를 문자열 길이의 오름차순으로 정렬하자. 그리고 `W[]`
를 `word` 로 순회한다.

* `int locmax = 0` 를 선언하고 local maximum chain count 을 저장한다.
* 문자열 `word` 를 한문자씩 제거한 문자열 `t` 를 만든다. `C[t]` 가
  있다면 `locmax = max(locmax, C[t] + 1)` 를 수행한다.
* `C[word] = locmax` 를 수행한다.
* `glbmax = max(glbmax, locmax)` 를 수행한다.

모든 반복을 마치면 `glbmax` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(NlgN) O(N)
```
