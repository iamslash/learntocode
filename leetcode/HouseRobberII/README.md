# Problem

[House Robber II](https://leetcode.com/problems/house-robber-ii/)

수열 `A[]` 가 주어진다. 연속되지 않은 숫자들을 선택하여 그 합이 최대가
되도록 하자.  `A[0]` 과 `A[n-1]` 은 서로 연속되었다고 하자.

# Idea

[House Robber](/leetcode/HouseRobber/README.md) 를 이용하여 쉽게 해결할 수 있다.

`A[0]` 과 `A[n-1]` 은 연속되어 있다. 따라서 `A[0..n-2]` 에서 선택한
수들의 최대합과 `A[1..n-1]` 에서 선택한 수들의 최대합을 비교하면 더 큰
값이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
