# Problem

일차원 배열 `A[]` 주어진다. `[a,b]` 영역의 분산을 구하라.

# Idea

정수열의 인덱스 `a` 부터 `b` 까지의 분산은 `a` 부터 `b` 까지 `(mean - a[i])^2` 의 합이다. 식을 전개하면 `sqpsum, psum, range_sum` 을 이용하여 구할 수 있다.

![](partial_sum_variance_eq.png)

# Implementation

* [c++11](a.cpp)

# Complexities

```
O(N)
O(N)
```
