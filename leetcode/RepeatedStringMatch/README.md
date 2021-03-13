# Problem

[Repeated String Match](https://leetcode.com/problems/repeated-string-match/)

문자열 `a, b` 가 주어진다. `a` 를 적당히 반복한 문자열에 `b` 가
포함되는지를 검사하라. 만약 포함되어 있다면 반복한 횟수를
구하라. 그렇지 않다면 `-1` 를 리턴하라.

# Idea

예를들어 `a = "abcd", b = "cdabcdab"` 의 경우를 살펴보자.

다음과 같은 변수를 선언한다.

> * `cnt` : `a` 의 반복 횟수
> * `s` : 비어 있는 문자열

`len(s) < len(b)` 인 동안 `s` 에 `a` 를 추가한다.

```
  a: abcd
  s: abcdabcd
cnt: 2
  b: cdabcdab
```

이때 `s` 에 `b` 가 포함되어 있는지 검사한다. 만약 없다면
한번 더 `s` 에 `a` 를 추가한다. 그리고 다시 검사한다.

```
  a: abcd
  s: abcdabcdabcd
cnt: 3
  b:   cdabcdab
```

이때 존재하지 않는다면 `a` 를 아무리 반복하더라도 `s` 에 `b` 는 포함될
수 없다. `-1` 를 리턴한다.

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complexity

```
O(N) O(N)
```
