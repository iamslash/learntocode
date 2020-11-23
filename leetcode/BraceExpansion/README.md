# Problem

[Brace Expansion](https://leetcode.com/problems/brace-expansion/)

# Idea

`{ , }` 와 소문자로 이루어진 문자열 `s` 가 주어진다.  curly braces 의
문자는 반드시 하나만 선택한다는 의미이다. curly braces 의 옵션을 고려하여
만들 수 있는 모든 문자열을 구하는 문제이다.

`vector<set<char>> D` 를 선언하여 옵션에 해당하는 문자들을 저장한다.
curly braces 가 없는 문자는 옵션이 하나인 것으로 생각한다.

`int m_rslt` 를 선언하고 가능한 문자열들을 모두 저장한다.
backtracking 으로 해결할 만 하다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(2^S) O(lgS)
```
