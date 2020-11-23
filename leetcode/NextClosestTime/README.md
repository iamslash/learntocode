# Problem

[Next Closest Time](https://leetcode.com/problems/next-closest-time/)

# Idea

시간과 분을 의미하는 문자열 `s` 가 주어진다. `s` 에 사용된 숫자들만
사용해서 가장 가까운 시간을 구하는 문제이다.

문자열 `s` 를 분으로 바꾸어 정수 `cur` 에 저장하자.
`cur` 를 하나씩 늘려가면서 그것이 `s` 에 사용된 숫자들로만
구성되었는지 검증한다. 

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```
