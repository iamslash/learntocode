# Problem

[Distinct Subsequences II](https://leetcode.com/problems/distinct-subsequences-ii/)

문자열 `s` 가 주어진다. distinct non-empty subsequence 들의
개수를 구하라.

# Idea

예를 들어 `s = "abc"` 를 살펴보자.

```
a
b
c
ab
ac
bc
abc
```

따라서 답은 7 이다.

subsequence 의 개수는 `2^n` 이다. 이때 공집합이 포함되어 있음을
유의하자.  예를 들어 `s = "abc"` 경우 subsequence 들의 개수는 `2^3 =
8` 이다.  여기서 중복된 subsequence 들을 제거하면 답이된다.

캐시 `C[]` 를 선언한다. `C[i]` 에 `s[0..i]` 의 non-empty distinct
subsequence 의 개수를 저장하자. `s[0..i]` 가 모두 distinct 이면 `C[i] =
C[i-1] * 2` 이다.

`end[26]` 를 선언하여 `end[i]` 에 `s[i]` 로 끝나는 non-empty distinct
subsequence 의 개수를 저장한다. 

`s[i] = 'a'` 이면 `s[0..i]` 가 모두 distinct 일 때 subsequence 들의
개수 `C[i-1] * 2` 를 구한다. 그리고 이전에 `a` 로 끝나는 non-empty
distinct subsequence 에 새로운 `a` 를 추가한 subsequence 들의 개수
`end[s[i]]` 를 제거한다.

즉, `C[i] = C[i-1] * 2 - end[s[i]]` 이다.

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
