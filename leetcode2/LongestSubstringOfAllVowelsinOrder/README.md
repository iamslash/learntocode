# Problem

> [Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/)

문자열 `s` 가 주어진다. `s` 는 `a, e, i, o, u` 와 같이 영문
소문자 모음으로만 구성되어 있다. 다음의 조건을 만족하는 부분문자열의
최대 길이를 구하라.

* 최대 길이 부분문자열은 `a, e, i, o, u` 모두를 갖고 있다.
* 최대 길이 부분문자열은 사전순으로 정렬되어 있다.

# Idea

예를 들어 `s = "aeiaaioaaaaeiiiiouuuooaauuaeiu"` 의 경우를
살펴보자.

```
          _____________
s: aeiaaioaaaaeiiiiouuuooaauuaeiu
```

따라서 답은 `13` 이다.

이 문제는 5 개의 숫자로 구성된 문자열에서 longest non-decreasing
substring 를 찾는 것과 같다.

`int ans = 0` 을 선언하여 답을 저장한다. `int len = 1` 을 선언하여
부분문자열의 길이를 저장한다. `int cnt = 1` 을 선언하여 서로다른 영문
소문자 모음의 개수를 저장한다. `int n` 을 선언하여 `s` 의 길이를
저장한다.

인덱스 `i` 를 `[1..n)` 동안 순회하면서 다음을 반복한다.

* `s.charAt(i-1) == s.charAt(i)` 이면 부분문자열의 길이를
  하나 증가한다. 즉, `len++` 를 수행한다.
  * `s.charAt(i-1) < s.char(i)` 이면 부분무자열의 길이를 증가하고
  모음의 개수도 증가하다. 즉, `len++, cnt++` 를 수행한다.
  * `s.charAt(i-1) > s.char(i)` 이면 새로운 부분문자열을 시작한다. 즉,
  `len = 1, cnt = 1` 을 수행한다.
* `cnt == 5` 이면 조건에 맞는 부분문자열을 발견한 것이다. 답을
  업데이트한다. 즉, `ans = max(ans, len)` 을 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
