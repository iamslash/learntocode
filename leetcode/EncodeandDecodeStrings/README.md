# Problem

> [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/)

다음과 같은 함수를 구현하라.

* 문자열 모음이 주어지면 하나의 문자로 인코딩하라.
* 하나의 문자열이 주어지면 문자열의 모음으로 디코딩하라.

# Idea

다음과 같은 방법으로 encode 한다.

```
["Hello","World"]

5:Hello5:World
```

substring 을 이용하여 `길이 구분자 문자열` 를 decode 한다.

# Implementation

* [c++11](a.cpp)
* [java8](Codec.java)

# Complexity

```
encode: O(N) O(N)
decode: O(N) O(N)
```
