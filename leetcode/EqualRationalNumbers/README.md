# Problem

* [Equal Rational Numbers](https://leetcode.com/problems/equal-rational-numbers/)

# Idea

유리수 `S, T` 가 주어진다. 소수점 이하 숫자들 중 반복되는 부분은 `(,)` 으로
표기한다. `S, T` 가 서로 같은 수인지 검증하는 문제이다.

`std::stod` 를 이용하여 `double` 로 변환하고 비교한다.  `double` 의
경우 유효비트가 52 bit 이므로 10진수로 따져 보면 소수점 이하 약 `1e15`
가 유효자리수이다.

따라서 반복되는 부분을 약 20 번 정도 반복해서 문자열을 만들고 `double` 로
변환한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```
