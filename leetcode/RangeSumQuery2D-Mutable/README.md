# Problem

> [Range Sum Query 2D - Mutable](https://leetcode.com/problems/range-sum-query-2d-mutable/)

행렬 `M[][]` 가 주어지면 그리드합을 구하는 문제이다.

# Idea

행과 열을 모두 더해서 부분합을 저장해 두면 그리드합을 `O(1)` 의
시간복잡도로 구할 수 있다.  그러나 한 원소를 갱신하게 되면 부분합을
상당히 많이 순회하여 갱신해야 한다.

각 행에 대한 열의 부분합을 저장해 두면 그리드합을 `O(W)` 의
시간복잡도로 구할 수 있다. 또한 한 원소를 갱신하게 되면 `O(W)` 의
시간복잡도로 변경할 수 있다.

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complextiy

```
sumRegion: O(W) O(HW)
   update: O(W) O(HW)
```
