# Problem

[Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix/)

문자열 `s` 가 주어진다. prefix 이면서 suffix 인 문자열들 중 가장
길이가 긴 것을 구하라.

# Idea

KMP algorithm 과 유사하다.

인덱스 `i = 1, j = 0` 를 선언한다. `lps[]` 를 선언하여 `lps[i]` 에
`s[i]` 로 끝나는 문자열들 중 가장 긴 prefix 이면서 suffix 인 문자열의
길이를 저장한다. 마지막에 `s.substring(0, lps[n-1])` 이 답이다.

예를 들어 `s = "level"` 의 경우를 살펴보자.

```
        i                i                i                i
   s: l e v e l      l e v e l      l e v e l      l e v e l      
      j              j              j              j
 lps: 0 0 0 0 0      0 0 0 0 0      0 0 0 0 0      0 0 0 0 1     
```

답은 `l` 이다.

다음은 `s = "ababa` 의 경우를 살펴보자.

```
        i                i                i                i
   s: a b a b a      a b a b a      a b a b a      a b a b a
      j                j                j                j
 lps: 0 0 0 0 0      0 0 1 0 0      0 0 1 2 0      0 0 1 2 3
```

답은 `aba` 이다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(1)
```
