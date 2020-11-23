# Problem

[Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/)

숫자 `n` 이 주어진다. `0` 부터 `n` 까지 gray code 를 생성해보자. 그
횟수를 구하라.

# Idea

[gray code](/fundamentals/bitmask/graycode/README.md) 로 생성한
이진수들은 연속된 두 수가 정확히 `1` bit 만 차이가 난다.

```
ans:  0 11 10  
  n: 11 01  0

ans:   0 110 101 100 
  n: 110 010 001   0
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
