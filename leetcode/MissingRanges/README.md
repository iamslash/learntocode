# Problem

* [Missing Ranges](https://leetcode.com/problems/missing-ranges/)

# Idea

수열 `V[]` 가 주어지고 숫자 `lo, hi` 가 주어진다.

이와 같이 수열이 주어지고 `lo, hi` 수열의 중간을 탐색할 때는
이전 값을 `prv` 에 넣어두고 현재 값을 `cur` 에 저장하면서
탐색하자.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```