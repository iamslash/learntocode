# Problem

* [Global and Local Inversions](https://leetcode.com/problems/global-and-local-inversions/)

# Idea

수열 `V` 가 주어지면 `global inversion (gi)` 과 `local inversion (li)` 이 
같은지 검증하는 문제이다. 이때 `N = V.size()` 일때 `V` 를 구성하는 
숫자는 `[0..N-1]` 이다.

정렬된 수열 `V = 0 1 2 3 4` 를 살펴보자. 
정렬되어 있다면 `gi=0, li=0` 이다.
숫자들이 자리이동할 때 `gi, li` 는 달라진다.
`li` 는 이웃한 숫자만 고려하지만 `gi` 는
이웃한 숫자와 더 멀리 떨어진 숫자도 대상이기 때문에
`gi >= li` 이다.

다음과 같이 `V` 의 숫자 `0` 이 자리이동을 할 때 `gi, li` 를 살펴보자.

```
V = 0 1 2 3 4    gi: 0, li: 0

V`= 1 0 2 3 4    gi: 1, li: 1
    2 1 0 3 4    gi: 3, li: 1
    3 1 2 0 4    gi: 5, li: 2
    4 1 2 3 0    gi: 7, li: 2
```

위와 같이 `abs(i - A[i]) > 1` 이면
`gi > li` 이다.

임의의 수열 `A` 는 `V` 의 순열이다.
`V` 를 순회하면서 `abs(i - A[i]) > 1`
를 검사한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```