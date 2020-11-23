# Problem

[Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray/)

# Idea

수열 `A[]` 가 주어진다. `i <= k < j` 인 경우 다음에 해당하는 최대
크기의 subarray 의 크기를 구하는 문제이다.

* `k` 가 홀수일 때는 `A[k] > A[k+1]` 이고 `k` 가 짝수일 때는 `A[k] <
  A[k+1]`
* `k` 가 짝수일 때는 `A[k] > A[k+1]` 이고 `k` 가 홀수일 때는 `A[k] <
  A[k+1]`
  
조건을 잘 살펴보면 `k` 가 짝수이냐 홀수이냐는 중요하지 않다. `A[k-2] >
A[k-1] < A[k]` 이거나 `A[k-2] < A[k-1] > A[k]` 를 만족하는 최대 크기의
subarray 를 찾는 것과 같다.

`int best = 0, int cand = 0` 를 선언하여 각각 답과 후보를 저장한다.

인덱스 `i` 를 이용하여 처음부터 끝까지 순회하면서 다음을 반복한다.

* `i >= 2` 이고 `A[i-2] > A[i-1] < A[i]` 이거나 `A[i-2] < A[i-1] > A[i]`
  인 경우 `cand++` 를 수행한다.
* `i >= 1` 이고 `A[i-1] != A[i]` 인 경우 `cand = 2` 로 초기화 한다.
* 그외의 경우는 `cand = 1` 로 초기화 한다.
* `best = max(best, cand)` 를 수행한다.

모든 반복을 마치면 `best` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
