# Problem

[Roman to Integer](https://leetcode.com/problems/roman-to-integer/)

# Idea

로마숫자로 구성된 문자열 `s` 가 주어진다. 이것을 숫자로 변환하는
문제이다.

다음과 같은 로마숫자가 존재한다.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

예를 들어 `IV` 를 살펴보자. 이것을 인덱스 `i` 를 이용하여 끝부터
처음방향으로 순회한다. `s[i]` 의 숫자가 `s[i+1]` 의 숫자보다 작을
경우는 `s[i+1]` 까지 누적한 합에서 `s[i]` 의 숫자를 빼준다.  만약
`s[i]` 의 숫자가 `s[i+1]` 의 숫자보다 크거나 같은 경우는 `s[i+1]` 까지
누적한 합에 `s[i]` 의 숫자를 더해준다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
```
