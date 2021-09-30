# Problem

[Maximum Product of the Length of Two Palindromic Subsequences](https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

문자열 `s` 가 주어진다. `s` 의 palindromic subsequence 두개를 고른다.
두개의 subsequence 는 인덱스가 distinct 하다. 즉, disjoint 하다.  그
길이를 서로 곱한 값중 최대를 구하라.

# Idea

예를 들어 `s = "leetcodecom"` 의 경우를 살펴보자.

```
     e   t       e
s: l e e t c o d e c o m
           c   d   c
```

따라서 답은 `3 * 3 = 9` 이다.

`int maxProd = 0` 을 선언하여 답을 저장한다.

문제의 조건에 의해 `2 <= s.length() <= 12` 이다. `s` 의 인덱스를
bitmask 로 표한하면 `4096` 개이다. `int[] C = new int[4096]` 을
선언하여 `s` 의 모든 subsequence 의 palindrome length 를 저장하자.

이제 `s` 에 포함되고 겹치지 않는 두 개의 subsequence 들을 각각 `a, b`
라고 하자.  `a * b` 를 `maxProd` 에 업데이트한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(4^N) O(1)
```
