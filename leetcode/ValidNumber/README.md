# Problem

* [Valid Number @ leetcode](https://leetcode.com/problems/valid-number/)

# Idea

문자열 `s` 가 주어진다. 숫자인지 검증하는 문제이다.

Deterministic Finite Automaton 을 설계하는 문제이다.

![](dfa.png)

현재 상태는 `st` 에 저장하고 숫자를 입력받았는지 여부는 `fg` 에 
저장한다.
먼저 `s` 를 trim 처리한다. 그리고 인덱스 `i` 를 이용하여
`s` 를 순회한다. 순회를 모두 마치면
현재 상태가 종료할만한 상태인지 검증한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
