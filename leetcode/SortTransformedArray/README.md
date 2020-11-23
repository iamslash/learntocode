# Problem

[Sort Transformed Array](https://leetcode.com/problems/sort-transformed-array/)

# Idea

수열 `V`, 숫자 `a, b, c` 가 주어지면 `a*x*x + b*x* +c` 를
원소로 하는 오름차순의 정렬된 수열을 구하는 문제이다.

이차함수이다. `a` 의 부호에 따라 위로 볼록하거나 아래로 볼록하다.

`i = 0, j = n - 1` 과 같이 두 인덱스를 이용하면
정렬된 함수의 값들을 얻어낼 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
