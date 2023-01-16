# Problem

배열 `A[]` 가 있다. 구간합이 `0` 에 가까운 것을 찾아 그 합을 구하라.

# Idea

배열 `A[]` 의 모든 숫자를 순회하면서 합을 구하면 `O(N^2)` 의 시간이 걸린다.

```
i       0  1  2  3  4  5  6  7  8  9
A[i]  -14  7  2  3 -8  4 -6  8  9 11
```

구간합 `rsum(i, j)` 는 다음과 같이 표현할 수 있다.

![](partial_sum_range_which_is_close_to_zero.png)

```
\sum_{k\ =\ i}^{j} = psum[j] - psum[i-1]
```

`rsum(i, j)` 가 `0` 에 가깝다는 말은 `psum[]` 두가지의 차이가 가장 적다는
뜻이다. `psum[]` 을 정렬해서 인접한 두녀석의 차이가 가장 작은 녀석을 찾아보자.

# Implementation

* [c++11](a.cpp)

# Complexities

```
O(NlgN)
O(N)
```
