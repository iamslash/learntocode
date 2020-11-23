# Problem

[Find Permutation](https://leetcode.com/problems/find-permutation/)

# Idea

`I, D` 로 구성된 문자열 `s` 가 주어진다. `I` 는 증가를 의미하고 
`D` 는 감소를 의미한다. 주어진 조건을 만족하는 사전순으로 가장 앞선 수열을
구하는 문제이다.

two pointers 전략을 이용하자. 즉 두개의 인덱스를 사용한다. 인덱스 `i`
를 하나씩 증가하고 `j` 는 하나씩 후퇴하는 방식을 사용한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
