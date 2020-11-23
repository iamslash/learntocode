# Problem

[Building H2O](https://leetcode.com/problems/building-h2o/)

# Idea

`H, O` 로 구성된 문자열이 입력되면 `HHOHHO...` 와 같이 출력하도록
구현하는 문제이다.

`condition_variable` 을 사용하자. 당연히 `mutex` 도 하나 필요하다.
`int m_i = 1` 를 선언하여 `m_i % 3 == 0` 이면 `O` 를 출력하도록 하자.
`m_i % 3 == 1 || m_i % 3 == 2` 이면 `H` 를 출력하도록 하자.

# Implementation

* [c++11](a.cpp)
