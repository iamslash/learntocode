# Problem

[Word Squares](https://leetcode.com/problems/word-squares/)

# Idea

문자열의 모음 `W[]` 가 주어진다. word square 가 가능한 문자열의
모음들을 구하는 문제이다.

예를 들어 `W[] = ("ball","area","lead","lady")` 이면
다음과 같이 한가지 word square 가 가능하다.

```
b a l l
a r e a
l e a d
l a d y
```

일단 첫행에 `ball` 를 하나 고른다. 두번째 행의 문자열은 `a` 로
시작해야 한다. 따라서 `area` 이다. 세번째 행의 문자열은 `le` 로
시작해야 한다. 따라서 `lead` 이다. 네번째 행의 무자열은 `lad` 로
시작해야 한다. 따라서 `lady` 이다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^K) O(N)
N: count of words
K: length of word
```
