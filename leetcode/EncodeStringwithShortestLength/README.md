# Problem

[Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length/)

# Idea

문자열 `s` 가 주어진다. `s` 를 `k[encoded_string]` 형태로
인코딩했을 때 가장 길이가 짧은 것을 구하는 문제이다. 인코딩한 것이
`s` 보다 길다면 인코딩 하지 않는다.

예를 들어 `s = "aaaaaaaaaa"` 를 살펴보자. 인코딩하면 `10[a]` 가 된다.
그러나 `s = "aaa"` 의 경우 인코딩하면 `3[a]` 가 되지만 길이가 4 이기
때문에 `"aaa"` 가 답이다.

참고로 어떤 문자열 `s` 가 그것보다 작은 문자열 `t` 의 반복으로
이루어졌다고 해보자. `s` 만 이용하여 `t` 를 찾아낼 수 있다.  `i =
(s+s).find(s, 1)` 를 수행하면 `t = s[:i]` 이다. 

예를 들어 `t = ab, s = abab` 의 경우를 살펴보자. `i =
"abababab".find(abab, 1) = 2` 이므로 `t = s[:2] = "ab"` 이다.

이제 `s` 에 대해 다음과 같이 3 가지 형태의 문자열들을 생성하고 길이가
가장 짧은 것을 답으로 하자.

0. 그냥 `s` 이다.
1. `s` 안에 반복된 문자열이 있다면 `k[encoded_string]` 형태로
   인코딩한다.
2. `s` 를 두그룹으로 나누어 각각 `k[encoded_string]` 형태로 인코딩한
   것을 더한다.

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complexity

```
O(N^3) O(N)
```
