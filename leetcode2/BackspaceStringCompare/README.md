# Problem

> [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/)

영문 소문자와 `#` 으로만 구성된 두 개의 문자열 `s, t` 가 주어진다.
`#` 은 Backspace 를 의미한다. 두개의 문자열을 읽어서 `#` 를
적용했을 때 결과가 같은지 검증하라.

# Idea

예를 들어 `s = "ab#c", t = "ad#c"` 의 경우를 살펴보자.

```
s: a b # c
t: a d # c

s: a c
t: a c
```

따라서 답은 true 이다.

이때 두개의 문자열을 뒤집어서 생각해 보자.

```
     i
  s: c # b a
  t: c # d a

sbS: c a
sbT: c a
```

두개의 `StringBuilder` 를 선언하여 linear traversal 할 수 있다.

# Implementation

* [go](a.go)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
