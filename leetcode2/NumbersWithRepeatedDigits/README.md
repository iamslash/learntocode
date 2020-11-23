# Problem

[Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits/)

숫자 `N` 이 주어진다. `N` 보다 작거나 같은 수들 중에
같은 숫자가 2 번 이상 반복되는 것들의 개수를 구하라.

# Idea

전체 개수 `N` 에서 distinct 숫자들의 개수를 구해서 제거한다.

backtracking 으로 distinct numbers 를 구한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(10^N) O(N)
```
