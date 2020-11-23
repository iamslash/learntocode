# Problem

[Two Sum II - Input array is sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

# Idea

수열 `A[]` 와 숫자 `T` 가 주어진다. 서로다른 두 숫자의 합이 `T` 와
같을 때 그 두 숫자의 인덱스를 구하는 문제이다. 인덱스는 1 부터
시작한다.

두개의 인덱스 `i, j` 를 선언하고 각각 처음과 끝을 가리킨다.  `A[i] +
A[j] < T` 이면 두 숫자의 합은 더욱 커져야 하므로 `i` 를
증가한다. `A[i] + A[j] > T` 이면 두 숫자의 합은 더욱 작아야 하므로 `j`
를 감소한다.

문제의 조건에 의해 반드시 답은 존재하기 때문에 반복을 마치면 `[i, j]`
가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
