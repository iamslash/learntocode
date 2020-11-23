# Problem

[Split Two Strings to Make Palindrome](https://leetcode.com/problems/split-two-strings-to-make-palindrome/)

두개의 문자열 `a, b` 가 주어진다. `a` 와 `b` 는 길이가 같다. 임의의
인덱스 `i` 에 대해서 `a[0..i) + b[i..]` 혹은 `b[0..i) + a[i..]` 가
palindrome 인지 검증하라.

# Idea

예를 들어 `a = "abdef", b = "fecab"` 의 경우를 살펴보자.

```
a: a b d e f
           .
b: f e c a b

s: f e c a b
   a e c a b
   a b c a b
   a b d a b
   a b d e b
   
b: f e c a b
       .
a: a b d e f

s: a b d e f
   f b d e f
   f e d e f   
```

`f e d e f` 는 palindrome 이다. 따라서 답은 `true` 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
