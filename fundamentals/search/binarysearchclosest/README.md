# Problem

[Find closest number in array](https://www.geeksforgeeks.org/find-closest-number-array/)

# Idea

수열 `A[]` 와 숫자 `K` 가 주어진다. `K` 와 가장 가까운 숫자를 구하는
문제이다.

먼저 인덱스 `l, h, m` 을 이용하여 binary search 한다. 만약 `m > 0`
이고 `A[m-1], A[m]` 사이에 `K` 가 있거나 `m < n` 이고 `A[m], A[m+1]`
사이에 `K` 가 있다면 둘 중 더 가까운 것을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(1)
```
