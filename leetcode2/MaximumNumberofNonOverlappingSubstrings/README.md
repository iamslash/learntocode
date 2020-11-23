# Problem

[Maximum Number of Non-Overlapping Substrings](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)

문자열 `s` 가 주어진다. 다음의 규칙을 만족하는 최대 개수의 부분문자열들을 구하라.

* The substrings do not overlap, that is for any two substrings
  s[i..j] and s[k..l], either j < k or i > l is true.
* A substring that contains a certain character c must also contain
  all occurrences of c.

# Idea

문자열을 구성하는 문자는 영문 소문자이기 때문에 모두 `26` 개이다.

예를 들어 `s = "adefaddaccc"` 의 경우를 살펴보자.

```
s: a d e f a d d a c c c
a: ---------------
d:   -----------
e:     -
f:       -
c:                 -----
```

따라서 곧 `["e","f","ccc"]` 이 답이다.

`vector<int> fst(26, INT_MAX)` 를 선언하여 영문 소문자별 시작 인덱스를
저장한다. `vector<int> lst(26, INT_MIN)` 를 선언하여 영문 소문자별
종료 인덱스를 저장한다.

`vector<string> ans` 를 선언하여 답을 저장한다. `vector<pair<int,int>>
events` 를 선언하여 영문 소문자들의 `{end index, begin index}` 를
저정하고 오름차순으로 정렬한다. 이제 겹치지 않는 영역의 부분문자열을
`ans` 에 저장한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
